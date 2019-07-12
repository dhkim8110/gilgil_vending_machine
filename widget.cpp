#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_Money(int n) {
    money += n;

    if(money <= 0){
        money = 0;
        ui->pb_Coffee->setEnabled(false);
        ui->pb_Tea->setEnabled(false);
        ui->pb_Gongcha->setEnabled(false);
    }else if(money >= 100){
        ui->pb_Coffee->setEnabled(true);
    }else if(money >= 150){
        ui->pb_Tea->setEnabled(true);
    }else if(money >= 200){
            ui->pb_Gongcha->setEnabled(true);
        }

    ui->lcd->display(QString::number(money));

}

void Widget::on_pb10_clicked()
{
    change_Money(10);
}

void Widget::on_pb50_clicked()
{
    change_Money(50);
}

void Widget::on_pb100_clicked()
{
    change_Money(100);
}

void Widget::on_pb500_clicked()
{
    change_Money(500);
}

void Widget::on_pb_Coffee_clicked()
{
    change_Money(-100);
}

void Widget::on_pb_Tea_clicked()
{
    change_Money(-150);
}

void Widget::on_pb_Gongcha_clicked()
{
    change_Money(-200);
}

void Widget::on_pb_Return_clicked()
{
    int d10, d50, d100, d500, dong;
    //500won
    dong = money / 500;
    d500 = dong;
    dong = money - (500*d500);

    //100won
    dong = dong / 100;
    d100 = dong;
    dong = dong - (d100*100);

    //50won
    dong = dong / 100;
    d100 = dong;
    dong = dong - (d100*100);

    //10won
    dong = dong / 50;
    d50 = dong;
    dong = dong - (d50*50);


    QMessageBox msg;
    msg.information(nullptr, "Return", "test");

}



