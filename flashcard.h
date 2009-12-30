#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QtGui/QWidget>
#include "ui_flashcard.h"
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPainter>
#include <QtGui/QSound>

#include "Card.h"
#include "report.h"

class Flashcard : public QWidget
{
    Q_OBJECT

public:
    Flashcard(QWidget *parent = 0);
    virtual ~Flashcard();

    void createMenu(QMenuBar*);

private:
    Ui::FlashcardClass ui;

    Card card;

    enum {front, back} side;

    void pickCard();
    void updateStats();

private slots:
	void cardClicked();
	void gaveAnswer();

	void setAscetic();
	void setBlackboard();
	void setPostit();

	void showReport();
};

#endif // FLASHCARD_H
