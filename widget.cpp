#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pb_Coffee->setEnabled(false);
    ui->pb_Tea->setEnabled(false);
    ui->pb_Gongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_Money(int n) {
    money += n;

    if(money >= 100){
        ui->pb_Coffee->setEnabled(true);
    }else{
        ui->pb_Coffee->setEnabled(false);
    }

    if(money >= 150){
        ui->pb_Tea->setEnabled(true);
    }else{
        ui->pb_Tea->setEnabled(false);
    }
    if(money >= 200){
            ui->pb_Gongcha->setEnabled(true);
    }else{
        ui->pb_Gongcha->setEnabled(false);
    }


    if(money <= 0) {
        money = 0;
        ui->pb_Coffee->setEnabled(false);
        ui->pb_Tea->setEnabled(false);
        ui->pb_Gongcha->setEnabled(false);
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
    d100 = dong / 100;
    dong = dong - (d100*100);

    //50won
    d50 = dong / 50;
    dong = dong - (d50*50);

    //10won
    d10 = dong / 10;
    dong = dong - (d10*10);


    QMessageBox msg;
    msg.information(nullptr, "Return",
     "500 won: " +QString::number(d500)
    +"\n 100 won:" +QString::number(d100)
    +"\n 50  won:" +QString::number(d50)
    +"\n 10  won:" +QString::number(d10), "");

    money = 0;
    ui->lcd->display(QString::number(money));
    ui->pb_Coffee->setEnabled(false);
    ui->pb_Tea->setEnabled(false);
    ui->pb_Gongcha->setEnabled(false);

/*
    msg.setText("500won: " +QString::number(d500)
                +"\n 100won:" +QString::number(d100)
                +"\n 50won:" +QString::number(d50)
                +"\n 10won:" +QString::number(d10));
    int ret = msg.exec();
*/
}



