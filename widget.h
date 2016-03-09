#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QColor>
#include <QColorDialog>
#include <QString>
#include "toolsbar.h"
#include "paintscene.h"
#include <QResizeEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *event);
    ~Widget();

private slots:
    void selectColor();
    //void slotTimer();

private:
    Ui::Widget *ui;
    ToolsBar *tool;
    //QTimer *timer;
    paintScene *scene;
    //void resizeEvent(QResizeEvent * event);
};

#endif // WIDGET_H
