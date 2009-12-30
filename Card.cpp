#include "Card.h"

#include <iostream>

Card::Card() : answer(skip) {
}

Card::~Card() {
}



Card Card::pick() {
	Card card;

	// select 20 cards with the highest fail rate, then pick a random one
    QSqlQuery query;
    query.exec("select id, text1, text2 "
    		   "from (select * from cards order by fail_rate desc limit 20) "
    		   "order by random() limit 1");
    if (query.next()) {
    	card.id    = query.value(0).toInt();
    	card.text1 = query.value(1).toString();
    	card.text2 = query.value(2).toString();
    }

	return card;
}

void Card::save() {
	if (answer > 0) {
		QSqlQuery query;
		bool okay = false;

		if (answer == wrong) {
			okay = query.exec(QString("update cards set wrong_answers = wrong_answers + 1, ") +
					          "fail_rate = cast(wrong_answers+1 + 1 as real) / (correct_answers + 1) " +
					          "where id=" + QString::number(id));
		} else {
			okay = query.exec(QString("update cards set correct_answers = correct_answers + 1, ") +
					          "fail_rate = cast(wrong_answers + 1 as real) / (correct_answers+1 + 1) " +
					          "where id=" + QString::number(id));
		}
		if (!okay) {
			std::cout << "SQL error: " << query.lastError().text().toStdString() << "\n";
		}
	}
}
