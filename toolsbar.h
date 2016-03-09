#ifndef TOOLSBAR_H
#define TOOLSBAR_H

#include <QWidget>

class ToolsBar : public QWidget
{
    Q_OBJECT

private:
    QColor  currentColor;
    int     currentWidth;
    bool    isRuber;

public:
    explicit ToolsBar(QWidget *parent = 0);
    void changeColor(QColor selectedColor);
    QColor getColor();
    int getWidth();
    bool getToolStatus();

signals:

public slots:   
    void changeWidth(int index);
    void selectRuber(bool checked);
};

#endif // TOOLSBAR_H
