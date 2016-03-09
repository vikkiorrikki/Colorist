#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    scene = new paintScene(ui->graphicsView_2);
    tool = new ToolsBar();
    QString filename = qApp->applicationDirPath()+"/minion_1.jpg";
    scene->setBrush(tool);
    scene->addPixmap(QPixmap(qApp->applicationDirPath()+"/2.PNG"));
    qDebug()<<filename;
    QGraphicsScene *test = new QGraphicsScene(ui->graphicsView_2);
    test->addPixmap(QPixmap(filename));

    ui->graphicsView_2->setScene(test);
   // ui->graphicsView_2->setScene(scene);

    connect(ui->btnColor, SIGNAL(clicked()),
            this, SLOT(selectColor()));
    //connect(ui->chckRuber, SIGNAL(clicked(bool)),
      //      tool, SLOT(selectRuber(bool)));
    connect(ui->cmbWidth, SIGNAL(currentIndexChanged(int)),
            tool, SLOT(changeWidth(int)));
    connect(ui->btnSetBrush, SIGNAL(clicked()),
            tool, SLOT(setBrush()));
    connect(ui->btnSetRuber, SIGNAL(clicked()),
            tool, SLOT(setRuber()));
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

