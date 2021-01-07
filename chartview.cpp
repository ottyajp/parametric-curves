#include "chartview.h"


chartview::chartview(QWidget *parent) : QChartView(new QChart(), parent)
{
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);

    setRenderHint(QPainter::Antialiasing);

    chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
}

void chartview::removeSeries() {
    chart()->removeAllSeries();
}

void chartview::addSeries(QLineSeries *s) {
    chart()->addSeries(s);
    chart()->createDefaultAxes();
}
