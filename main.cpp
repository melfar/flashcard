#include "flashcard.h"

#include <QtGui>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtGui/QMainWindow>

bool initializeDb() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("flashcard.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
          "Database file not found: flashcard.db\n\n"
          "Click Cancel to exit.", QMessageBox::Cancel);
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!initializeDb())  return 1;

    Flashcard *flashcard = new Flashcard();

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(flashcard);

	flashcard->createMenu(mainWindow.menuBar());

	mainWindow.show();

    return a.exec();
}
