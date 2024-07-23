#include "balance.h"
#include "ui_balance.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

Balance::Balance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
}

Balance::~Balance()
{
    delete ui;
}

void Balance::showNewBalance(int newBalance) {
    QString newBalanceText = "Balance: " + QString::number(newBalance);
    ui->label_Balance->setText(newBalanceText);
}


void Balance::on_pushButton_Cancel_Balance_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void Balance::on_pushButton_Back_Balance_clicked()
{
    this->close();
    MainPage *mainpage = new MainPage();
    mainpage->show();
}





