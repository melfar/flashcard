#include "report.h"

#include <iostream>

Report::Report(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);

	ReportGraph* reportGraph = new ReportGraph(ui.scrollArea);
	reportGraph->setGeometry(QRect(0, 0, 200, 200));
	ui.scrollArea->setWidget(reportGraph);

	QSqlQuery query;
	query.exec("select not_shown, unlearned, medium_learned, well_learned "
				   "from card_stats order by updated_at desc limit 1");
	if (query.next()) {
		ui.lblNotShown     ->setText( query.value(0).toString() + " not shown" );
		ui.lblUnlearned    ->setText( query.value(1).toString() + " unlearned" );
		ui.lblMediumLearned->setText( query.value(2).toString() + " medium-learned" );
		ui.lblWellLearned  ->setText( query.value(3).toString() + " well-learned" );
	}
}

Report::~Report()
{

}

// close on tap
void Report::mouseReleaseEvent(QMouseEvent*) {
	close();
}

ReportGraph::ReportGraph(QWidget *parent)
    : QWidget(parent)
{
}



void ReportGraph::paintEvent(QPaintEvent*) {
	QSqlQuery query;

	query.exec("select not_shown + unlearned + medium_learned + well_learned, "
			   "not_shown, unlearned, medium_learned, well_learned "
			   "from card_stats order by updated_at asc");

	int i = 0;
	QPainter painter(this);

	while(query.next()) {
		double fraction = height() / query.value(0).toInt();
		int not_shown      = query.value(1).toInt() > 0 ? fraction * query.value(1).toInt() : 0;
		int unlearned      = query.value(2).toInt() > 0 ? fraction * query.value(2).toInt() : 0;
		int medium_learned = query.value(3).toInt() > 0 ? fraction * query.value(3).toInt() : 0;
		int well_learned   = query.value(4).toInt() > 0 ? fraction * query.value(4).toInt() : 0;

		painter.setPen(QColor("#000000"));
		painter.drawLine(i, 0, i, height());

		painter.setPen(QColor("#f0f0f0"));
		painter.drawLine(i, 0, i, well_learned);
		painter.setPen(QColor("#00d0f0"));
		painter.drawLine(i, well_learned, i, well_learned+medium_learned);
		painter.setPen(QColor("#0070f0"));
		painter.drawLine(i, well_learned+medium_learned, i, well_learned+medium_learned+unlearned);


		i++;
	}
}
