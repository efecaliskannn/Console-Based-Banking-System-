#include "deposit.h"
#include "ui_deposit.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "databaseconnection.h"
#include <QInputDialog>
#include <QSqlError>
#include "bankaccount.h"
#include "deposit.h"
#include "balance.h"

//Deposit::Deposit(BankAccount account, QWidget *parent) :
//    QMainWindow(parent),
//    m_account(account),
//    ui(new Ui::Deposit)
//{
//    ui->setupUi(this);
//}

Deposit::Deposit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
    m_account = new BankAccount();
    m_db = new DatabaseConnection();
}

Deposit::~Deposit()
{
    delete ui;
    delete m_account;
    delete m_db;
}

void Deposit::on_pushButton_Confirm_Deposit_clicked()

{


    QString accountName = m_account->getName();
    QString depositAmountStr = ui->lineEdit_DepositAmount->text();
    int depositAmount = depositAmountStr.toInt();

    if (depositAmount <= 0)
    {
        QMessageBox::warning(this, "Error", "Please enter a valid deposit amount.");
        return;
    }
    if (!m_db->Connect()){
        qDebug() << "Database connection error";
        return;
    }
    qDebug() << depositAmount;
    int currentBalance = m_account->getBalance();
    qDebug() << "1";
    //  qDebug() << QSqlDatabase::drivers();

    qDebug() << currentBalance;
    qDebug() << depositAmount;

    int newbalance = currentBalance + depositAmount;
    qDebug() << "2";
    QSqlDatabase db = m_db->getDatabase();
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());
    }
    if (!m_db->Connect()){
        qDebug() << "Database connection error";
        return;
    }



    qDebug() << "3";
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE login_table SET Balance = :balance WHERE Name = :name");
    updateQuery.bindValue(":balance", newbalance);
    //    updateQuery.bindValue(":name", m_account->getName());     bunu kullancaksan bunu sil =QString accountName = m_account->getName();
    updateQuery.bindValue(":name", accountName);
    if (updateQuery.exec()) {
        qDebug() << "Balance updated in the database.";
        qDebug() << "4";
        m_account->setBalance(newbalance);
        qDebug() << "5";
        Balance *balancePage = new Balance(); // Balance sayfasının bir örneği
        balancePage->showNewBalance(newbalance); // Yeni bakiyeyi göstermek için işlevi çağırın
        qDebug() << newbalance;
        balancePage->show(); // Balance sayfasını göster
        this->close();

    } else {
        qDebug() << "Database error: " << updateQuery.lastError().text();
    }
    qDebug() << "6";




    // Kullanıcıya bilgi ver
    QMessageBox::information(this, "Success", "Deposit successful. New balance: " + QString::number(depositAmount));
    //    m_db->Disconnect();
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());
    }
}



//this->close();

void Deposit::on_pushButton_Cancel_Deposit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}
void Deposit::on_pushButton_Back_Deposit_clicked()
{
    this->close();
    MainPage *mainpage = new MainPage();
    mainpage->show();
}















