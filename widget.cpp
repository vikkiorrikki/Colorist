#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(anySlot()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::anySlot(){
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_clicked()
{

}
