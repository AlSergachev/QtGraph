#ifndef QTGRAPH_H
#define QTGRAPH_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_qtgraph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtGraph; }
QT_END_NAMESPACE

class QtGraph : public QMainWindow
{
    Q_OBJECT

public:
    QtGraph(QWidget *parent = nullptr);
    ~QtGraph();

private:
    Ui::QtGraph *ui;
    int x1, x2, y1, y2;
    QGraphicsScene* scene = new QGraphicsScene;
    void SceneClear();

public slots:
    void pushButton_show_clicked();
    void pushButton_clear_clicked();
    void sl_update(int value = 2);
};
#endif // QTGRAPH_H
