#include "QtGraph.h"

QtGraph::QtGraph(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->rotate(270);
    SceneClear();
    connect(ui.pushButton_show, SIGNAL(clicked()), this, SLOT(pushButton_show_clicked));
    connect(ui.pushButton_clear, SIGNAL(clicked()), this, SLOT(pushButton_clear_clicked));
    connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(sl_update(int)));

    ui.graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);


}

void QtGraph::SceneClear()
{
    scene->clear();
    QPen grid(Qt::green, 1.0);
    grid.setCosmetic(true);
    scene->addLine(-90, 0, 90, 0, grid);
    scene->addLine(0, 90, 0, -90, grid);
    ui.graphicsView->setScene(scene);
}

void QtGraph::pushButton_show_clicked()
{
    x1 = ui.spinBox_x1->value();
    x2 = ui.spinBox_x2->value();
    y1 = ui.spinBox_y1->value();
    y2 = ui.spinBox_y2->value();

    emit sl_update();
}

void QtGraph::sl_update(int value)
{

    QPen point(Qt::red, 1.6);
    point.setCosmetic(true);
    double rad = 2;
    scene->addEllipse(x1 - rad, y1 - rad, 1, 1);
    scene->addEllipse(x2 - rad, y2 - rad, 1, 1);
    ui.graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    SceneClear();
    rad = value;
    scene->addEllipse(x1 - rad, y1 - rad, rad * 2.0, rad * 2.0, point, QBrush(Qt::NoBrush));
    scene->addEllipse(x2 - rad, y2 - rad, rad * 2.0, rad * 2.0, point, QBrush(Qt::NoBrush));
    ui.graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}


void QtGraph::pushButton_clear_clicked()
{
    SceneClear();
    ui.graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

}