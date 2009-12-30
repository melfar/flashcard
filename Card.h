/*
 * Card.h
 *
 *  Created on: Dec 28, 2009
 *      Author: buzinvs
 */

#ifndef CARD_H_
#define CARD_H_

#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class Card {
public:
	Card();
	~Card();

	QString text1;
	QString text2;
    enum answer_type {skip, wrong, correct} answer;

	static Card pick();

	void save();

private:
	int id;
};

#endif /* CARD_H_ */
