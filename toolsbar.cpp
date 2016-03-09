#include "toolsbar.h"
#include <QDebug>


ToolsBar::ToolsBar(QWidget *parent) : QWidget(parent)
{
    currentWidth = 1;
    isRuber = false;
    currentColor.setRgb(Qt::black);
}

void ToolsBar:: changeColor(QColor selectedColor)
{
    currentColor = selectedColor;
    qDebug()<<"its work!";

}

void ToolsBar:: changeWidth(int index)
{
    currentWidth = index+1;
    qDebug()<<"width changed to"<< currentWidth;
}

void ToolsBar:: setBrush()
{
    isRuber = false;
}

void ToolsBar:: setRuber()
{
    isRuber = true;
}
/*void ToolsBar:: selectRuber(bool checked)
{
    if(checked)
    {
         qDebug()<<"Выбрали ластик";
         isRuber = true;
    }
    else
    {
        qDebug()<<"Убрали ластик";
        isRuber = false;
    }
}*/

QColor ToolsBar:: getColor()
{
    return this->currentColor;
}

int ToolsBar:: getWidth()
{
    return this->currentWidth;
}

bool ToolsBar:: getToolStatus()
{
    return this->isRuber;
}
