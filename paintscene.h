#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include "toolsbar.h"

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(const QRectF & sceneRect, QObject *parent = 0);
    void setBrush(ToolsBar *brush);
    void setBrushType(bool status);
    ~paintScene();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    ToolsBar    *myBrush;
    QBrush      *brushType;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
