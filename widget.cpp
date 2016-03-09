#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ui->graphicsView_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    scene = new paintScene(ui->graphicsView_2->rect(), ui->graphicsView_2);
    tool = new ToolsBar();
    scene->setBrush(tool);
    QGraphicsScene *leftScene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(leftScene);

    ui->graphicsView_2->setScene(scene);

    connect(ui->btnColor, SIGNAL(clicked()),
            this, SLOT(selectColor()));
    connect(ui->cmbWidth, SIGNAL(currentIndexChanged(int)),
            tool, SLOT(changeWidth(int)));
    connect(ui->btnSetBrush, SIGNAL(clicked()),
            tool, SLOT(setBrush()));
    connect(ui->btnSetRuber, SIGNAL(clicked()),
            tool, SLOT(setRuber()));

}
void Widget:: resizeEvent(QResizeEvent *event)
{
    ui->graphicsView->scene()->setForegroundBrush(
                QPixmap(qApp->applicationDirPath()+"/min-rdy.jpg").scaled(
                ui->graphicsView->geometry().width(),
                ui->graphicsView->geometry().height(), Qt::IgnoreAspectRatio));

    scene->setForegroundBrush(
                QPixmap(qApp->applicationDirPath()+"/55455.png").scaled(
                ui->graphicsView_2->geometry().width(),
                ui->graphicsView_2->geometry().height(), Qt::IgnoreAspectRatio));
}
Widget::~Widget()
{
    delete ui;
}
void Widget::selectColor()
{

    QColor selectedColor = QColorDialog::getColor();
    ui->btnColor->setStyleSheet("background-color: rgb("
                                +QString::number(selectedColor.red())+","
                                +QString::number(selectedColor.green())+","
                                +QString::number(selectedColor.blue())+");");
    tool->changeColor(selectedColor);
}

