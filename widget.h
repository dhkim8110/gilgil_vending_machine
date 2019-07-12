#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void change_Money(int n);
    int money{0};

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pb_Coffee_clicked();

    void on_pb_Tea_clicked();

    void on_pb_Gongcha_clicked();

    void on_pb_Return_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
