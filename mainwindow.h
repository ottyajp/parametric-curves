#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "chartview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_outerCircleDrawButton_clicked();

    void on_removeAllSeriesButton_clicked();

    void on_innerCircleDrawButton_clicked();

    void on_actionRemove_All_Series_triggered();

    void on_actionDraw_outer_circle_after_Remove_All_Series_triggered();

    void on_actionDraw_inner_circle_triggered();

private:
    Ui::MainWindow *ui;
    chartview *cv;
};
#endif // MAINWINDOW_H
