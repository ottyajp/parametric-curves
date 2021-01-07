#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPointF>

#include <cmath>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cv = new chartview();
    this->ui->mainLayout->insertWidget(0, cv, 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_outerCircleDrawButton_clicked()
{
    QLineSeries *s = new QLineSeries();
    for (double t = 0.0; t<10.0; t += 0.01) {
        QPointF *p = new QPointF();
        double x = cos(t);
        double y = sin(t);
        p->setX(x);
        p->setY(y);
        s->append(*p);
    }
    this->cv->addSeries(s);
}

void MainWindow::on_removeAllSeriesButton_clicked()
{
    this->cv->removeSeries();
}

void MainWindow::on_innerCircleDrawButton_clicked()
{
    QLineSeries *s = new QLineSeries();
    for (double t = 0.0; t<10.0; t += 0.01) {
        QPointF *p = new QPointF();
        // この辺の定数をパラメータとして設定できるようにして遊ぶ
        double innerRadius = this->ui->innerRadius->text().toDouble();
        double ratio = this->ui->ratio->text().toDouble();
        double x = innerRadius*cos(t) + innerRadius*cos(ratio*t);
        double y = innerRadius*sin(t) + innerRadius*sin(ratio*t);
        p->setX(x);
        p->setY(y);
        s->append(*p);
    }
    this->cv->addSeries(s);
}

void MainWindow::on_actionRemove_All_Series_triggered()
{
    this->cv->removeSeries();
}

void MainWindow::on_actionDraw_outer_circle_after_Remove_All_Series_triggered()
{
    this->cv->removeSeries();
    this->on_outerCircleDrawButton_clicked();
}

void MainWindow::on_actionDraw_inner_circle_triggered()
{
    this->on_innerCircleDrawButton_clicked();
}
