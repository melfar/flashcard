#include "flashcard.h"

#include <iostream>

Flashcard::Flashcard(QWidget *parent)
    : QWidget(parent), side(front)
{
	ui.setupUi(this);

	// card
	ui.frontSideButton->connect(ui.frontSideButton, SIGNAL(clicked()), this, SLOT(cardClicked()));
	ui.backSideButton->connect(ui.backSideButton, SIGNAL(clicked()), this, SLOT(cardClicked()));

	// buttons
	ui.skipButton->connect(ui.skipButton, SIGNAL(clicked()), this, SLOT(gaveAnswer()));
	ui.wrongButton->connect(ui.wrongButton, SIGNAL(clicked()), this, SLOT(gaveAnswer()));
	ui.correctButton->connect(ui.correctButton, SIGNAL(clicked()), this, SLOT(gaveAnswer()));

	pickCard();
}

Flashcard::~Flashcard()
{

}

void Flashcard::createMenu(QMenuBar *menuBar) {
	QMenu *theme = menuBar->addMenu("&Theme");

	QAction *ascetic = new QAction("&Ascetic", this);
	ascetic->setCheckable(true);
	ascetic->setChecked(true);
    connect(ascetic, SIGNAL(triggered()), this, SLOT(setAscetic()));

	QAction *blackboard = new QAction("&Blackboard", this);
	blackboard->setCheckable(true);
    connect(blackboard, SIGNAL(triggered()), this, SLOT(setBlackboard()));

	QAction *postit = new QAction("&Post-it note", this);
	postit->setCheckable(true);
    connect(postit, SIGNAL(triggered()), this, SLOT(setPostit()));

	// put actions into a group, that makes them mutually exclusive
	QActionGroup *actionGroup = new QActionGroup(this);
	actionGroup->addAction(ascetic);
	actionGroup->addAction(blackboard);
	actionGroup->addAction(postit);

	// add actions to the menu
	theme->addAction(ascetic);
	theme->addAction(blackboard);
	//theme->addAction(postit);

	QMenu *view = menuBar->addMenu("&Report");
	QAction *showReport = new QAction("&Show report", this);
	connect(showReport, SIGNAL(triggered()), this, SLOT(showReport()));
	view->addAction(showReport);
}


void Flashcard::pickCard() {
	card = Card::pick();
	ui.frontSideButton->setText(card.text1);
	ui.backSideButton->setText(card.text2);

	// show front side
	side = front;
	ui.cardStack->setCurrentIndex(0);
	// show Skip button
	ui.buttonStack->setCurrentIndex(0);
}

void Flashcard::cardClicked() {
	// show Wrong and Correct buttons
	ui.buttonStack->setCurrentIndex(1);

	// flip sides
	side = (side == front) ? back : front;
	ui.cardStack->setCurrentIndex(side == front ? 0 : 1);

//	if (side == back) {
//		QSound sound("side2/" + card.text2 + ".wav");
//		sound.play();
//	}
}

void Flashcard::gaveAnswer() {
	Card::answer_type answer = Card::skip;

	if(sender()->objectName() == "skipButton")    answer = Card::skip;
	if(sender()->objectName() == "wrongButton")   answer = Card::wrong;
	if(sender()->objectName() == "correctButton") answer = Card::correct;

	//std::cout << "Gave answer: " << (int)answer << "\n";

	card.answer = answer;
	card.save();

	pickCard();
	updateStats();
}

void Flashcard::setAscetic() {
	setStyleSheet("");
	ui.frontSideButton->setStyleSheet("");
	ui.backSideButton->setStyleSheet("");
}
void Flashcard::setBlackboard() {
	//setStyleSheet("background-color: white");
	ui.frontSideButton->setStyleSheet("border-image: url(:/images/green-blackboard.jpg) 25 repeat repeat;"
			                          "border: 25; color: white;");
	ui.backSideButton->setStyleSheet("border-image: url(:/images/black-blackboard.jpg) 25 repeat repeat;"
			                         "border: 25; color: #ffee22;");
}
void Flashcard::setPostit() {
	parentWidget()->setStyleSheet("background: url(:/images/postit.jpg) no-repeat;"
			                      "background-position: center; "
			                      "border: 0; color: black;");
	setStyleSheet("background: none");
}

void Flashcard::showReport() {
	Report *report = new Report(this);
	report->setGeometry(rect());
	report->show();
}

void Flashcard::updateStats() {
    QSqlQuery query;
    query.exec("select cards_shown from info");

    if (query.next()) {
		int cards_shown = query.value(0).toInt();

		// update stats every 1 draws
		if (cards_shown % 1 == 0) {
			query.exec("insert into card_stats(not_shown, unlearned, medium_learned, well_learned) "
					   "values( (select count(*) from cards where correct_answers = 0 and wrong_answers = 0),"
					   "        (select count(*) from cards where (correct_answers > 0 or wrong_answers > 0) and fail_rate > 1.0),"
					   "        (select count(*) from cards where fail_rate between 0.2 and 1.0),"
					   "        (select count(*) from cards where fail_rate < 0.2) )");
		}
    }

    query.exec("update info set cards_shown = cards_shown + 1");
}
