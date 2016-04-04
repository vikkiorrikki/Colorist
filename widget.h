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
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QtXml/QtXml>
#include <QtGui>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *event);
    void parseXML(const QDomNode xmlNode);
    ~Widget();

private slots:
    void selectColor();
    void savePic();


    void on_btnStart_clicked();

    void on_btnMenu_clicked();

    void on_btnRepeat_clicked();

    void on_btnFinish_clicked();

    void on_btnSavePic_clicked();

private:
    Ui::Widget *ui;
    ToolsBar *tool;
    QMap<QString, QMap<QString, QList<QString>* >* > *levels;
    int current_level;
    paintScene *scene;
    void loadLevel();
    int getResult();

};

#endif // WIDGET_H
