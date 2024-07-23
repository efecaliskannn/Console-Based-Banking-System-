#include "withdraw.h"
#include "ui_withdraw.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "bankaccount.h"
#include "databaseconnection.h"
#include "balance.h"

Withdraw::Withdraw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Withdraw)
{
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;

}

void Withdraw::on_pushButton_Cancel_Withdraw_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void Withdraw::on_pushButton_Back_Withdraw_clicked()
{
    this->close();
    MainPage *mainpage = new MainPage();
    mainpage->show();
}


void Withdraw::on_pushButton_Confirm_Withdraw_clicked()
{

}

