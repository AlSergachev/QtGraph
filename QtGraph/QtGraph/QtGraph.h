#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGraph.h"
#include <QGraphicsScene>

class QtGraph : public QMainWindow
{
    Q_OBJECT

public:
    QtGraph(QWidget* parent = Q_NULLPTR);

private:
    Ui::QtGraphClass ui;
    int x1, x2, y1, y2;
    QGraphicsScene* scene = new QGraphicsScene(ui.graphicsView);
    void SceneClear();

public slots:
    void pushButton_show_clicked();
    void pushButton_clear_clicked();
    void sl_update(int value = 2);


};
