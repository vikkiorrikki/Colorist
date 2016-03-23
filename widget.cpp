#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(0);

    tool = new ToolsBar();
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView_2->setSceneRect(0, 0, 600, 800);

    QGraphicsScene *leftScene = new QGraphicsScene();
    scene = new paintScene(ui->graphicsView_2->rect(), ui->graphicsView_2);
    scene->setBrush(tool);
    ui->graphicsView->setScene(leftScene);
    ui->graphicsView_2->setScene(scene);

    QString qwer = "qweqweq";
    qDebug() << qwer;

    QDomDocument domDoc;
    QFile        file(qApp->applicationDirPath()+"/levels.xml");
    levels = new  QMap<QString, QMap<QString, QList<QString>* >* >();
    if(file.open(QIODevice::ReadOnly)) {
        if(domDoc.setContent(&file)) {
            QDomElement domElement= domDoc.documentElement();
            parseXML(domElement);
        }
        file.close();
    }


    connect(ui->btnColor, SIGNAL(clicked()),
            this, SLOT(selectColor()));
    connect(ui->cmbWidth, SIGNAL(currentIndexChanged(int)),
            tool, SLOT(changeWidth(int)));
    connect(ui->btnSetBrush, SIGNAL(clicked()),
            tool, SLOT(setBrush()));
    connect(ui->btnSetRuber, SIGNAL(clicked()),
            tool, SLOT(setRuber()));
    connect(ui->btnFinish, SIGNAL(clicked()),
            this, SLOT(savePic()));


}
void Widget:: resizeEvent(QResizeEvent *)
{
    ui->graphicsView->scene()->setBackgroundBrush(
                QPixmap(ui->graphicsView->scene()->backgroundBrush().texture()).scaled(
                ui->graphicsView->geometry().width(),
                ui->graphicsView->geometry().height(), Qt::IgnoreAspectRatio));

    scene->setForegroundBrush(
                QPixmap(scene->foregroundBrush().texture()).scaled(
                ui->graphicsView_2->geometry().width(),
                ui->graphicsView_2->geometry().height(), Qt::IgnoreAspectRatio));

}
Widget::~Widget()
{
    delete ui;
}
void Widget:: savePic()
{
    QString fileName= QFileDialog::getSaveFileName(this, "Save image", QCoreApplication::applicationDirPath(), "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)" );
    if (!fileName.isNull())
        {
            QPixmap pixMap = this->ui->graphicsView_2->grab();
            pixMap.save(fileName);
        }
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

void Widget::parseXML(const QDomNode node)
{
    QString theme, complex;
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull()) {
        if(domNode.isElement()) {
           QDomElement domElement = domNode.toElement();
           if(!domElement.isNull()) {
               if( domElement.tagName() == "theme")
               {
                   theme = domElement.attribute("title");
                   ui->listWidget->addItem(theme);
               }
               if( domElement.tagName() == "complexity")
               {
                   complex = domElement.attribute("id");

                   QMap<QString, QList<QString>* > *map;
                   if(levels->value(domElement.parentNode().toElement().attribute("title")) == NULL)
                   {
                       map = new QMap<QString, QList<QString>* >() ;
                   }
                   else
                   {
                       map = levels->value(domElement.parentNode().toElement().attribute("title"));
                   }
                   map->insert(complex, new QList<QString>() );
                   levels->insert(domElement.parentNode().toElement().attribute("title"), map);
               }
               if(domElement.tagName() == "level")
               {
                   levels->value(domElement.parentNode().toElement().parentNode().toElement().attribute("title"))->value(domElement.parentNode().toElement().attribute("id"))->push_back(domElement.attribute("file"));
               }
           }
        }
        parseXML(domNode);
        domNode = domNode.nextSibling();
     }
}






void Widget::on_btnStart_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(0);
    this->resizeEvent(NULL);
    int theme = ui->listWidget->currentRow();
    QString str =  ui->listWidget->item(theme)->text();
    int val = ui->sldDificult->value();
    qDebug() << qApp->applicationDirPath()+
                "/"+
                levels->value(str)->value(QString::number(val))->at(0);
    ui->graphicsView->scene()->setBackgroundBrush(QPixmap(qApp->applicationDirPath()+
                                                 "/templ_"+
                                                 levels->value(str)->value(QString::number(val))->at(0))
            .scaled(
                            ui->graphicsView->geometry().width(),
                            ui->graphicsView->geometry().height(), Qt::IgnoreAspectRatio));
    qDebug() << ui->graphicsView_2->geometry().width();
    qDebug() << ui->graphicsView_2->geometry().height();
   scene->setForegroundBrush(QPixmap(qApp->applicationDirPath()+
                                                 "/templ_"+
                                                 levels->value(str)->value(QString::number(val))->at(0))
                             .scaled(
                                             ui->graphicsView_2->geometry().width(),
                                             ui->graphicsView_2->geometry().height(), Qt::IgnoreAspectRatio));

    ui->stackedWidget->setCurrentIndex(2);

}

void Widget::on_btnMenu_clicked()
{
    QMessageBox msg;
    msg.setText("Выход в главное меню");
    msg.setInformativeText("Вы уверены?");
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Ok);

    int ret = msg.exec();
    if( ret == QMessageBox::Cancel) return;
    ui->stackedWidget->setCurrentIndex(0);
}
