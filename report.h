#ifndef REPORT_H
#define REPORT_H

#include <QtGui/QWidget>
#include "ui_report.h"

#include <QtGui/QPainter>
#include <QtSql/QSqlQuery>


class Report : public QWidget
{
    Q_OBJECT
public:
    Report(QWidget *parent);
    virtual ~Report();
private:
    Ui::ReportClass ui;
    void mouseReleaseEvent(QMouseEvent*);
};


class ReportGraph : public QWidget {
    Q_OBJECT

public:
    ReportGraph(QWidget *parent);
private:
	void paintEvent(QPaintEvent*);
};


#endif // REPORT_H
