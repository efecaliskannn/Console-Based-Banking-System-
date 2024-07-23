#include "mainpage.h"
#include "ui_mainpage.h"
#include "mainpage.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "databaseconnection.h"
MainPage::MainPage(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    m_db = new DatabaseConnection;
}

MainPage::~MainPage()
{
    delete ui;
    delete m_db;
}


void MainPage::on_pushButton_Balance_clicked()
{
    //    DatabaseConnection connection;
    //    if (!connection.Connect()){
    //        qDebug() << "Database connection error";
    //        return;
    //    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/efe/database/database.db");

    if (!db.open()){
        //    if (!m_db->Connect()){
        qDebug() << "Database connection error";
        return;
    }
    //    QString connectionName = m_db->getConnectionName();
    this->close();
    Balance *balance = new Balance();
    balance->show();
    //    m_db->Disconnect();
    //    QSqlDatabase::removeDatabase(connectionName);

    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}


void MainPage::on_pushButton_Withdraw_clicked()
{
    //    DatabaseConnection connection;
    //    if (!connection.Connect()){
    //        qDebug() << "Database connection error";
    //        return;
    //    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/efe/database/database.db");

    //    if (!m_db->Connect()){
    if (!db.open()){
        qDebug() << "Database connection error";
        return;
    }
    this->close();
    Withdraw *withdraw = new Withdraw();
    withdraw->show();
    //    connection.Disconnect();
    //    m_db->Disconnect();
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}


void MainPage::on_pushButton_Deposit_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/efe/database/database.db");
    //    DatabaseConnection connection;
    //    if (!connection.Connect()){
    //        qDebug() << "Database connection error";
    //        return;
    //    }
    //    if (!m_db->Connect()){
    if (!db.open()){
        qDebug() << "Database connection error";
        return;
    }
    this->close();
    Deposit *deposit = new Deposit();
    deposit->show();
    //    m_db->Disconnect();
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}


void MainPage::on_pushButton_Transfer_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/efe/database/database.db");
    //    DatabaseConnection connection;
    //    if (!connection.Connect()){
    //        qDebug() << "Database connection error";
    //        return;
    //    }
    if (!db.open()){
        //    if (!m_db->Connect()){
        qDebug() << "Database connection error";
        return;
    }
    this->close();
    Transfer *transfer =new Transfer();
    transfer->show();
    //    m_db->Disconnect();
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}


void MainPage::on_pushButton_Cancel2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

