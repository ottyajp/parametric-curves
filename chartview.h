#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegendMarker>

QT_CHARTS_USE_NAMESPACE

class chartview : public QChartView
{
    Q_OBJECT
public:
    explicit chartview(QWidget *parent = 0);

    void removeSeries();
    void addSeries(QLineSeries *s);
};

#endif // CHARTVIEW_H
