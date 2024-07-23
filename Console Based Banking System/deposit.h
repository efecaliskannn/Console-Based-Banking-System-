#ifndef DEPOSIT_H
#define DEPOSIT_H
#include <QSqlDatabase>
#include <QMainWindow>
#include <QMessageBox>
#include "mainpage.h"
#include "bankaccount.h"
#include "databaseconnection.h"

namespace Ui {
class Deposit;
}
class Deposit : public QMainWindow
{
    Q_OBJECT

public:

//    Deposit(BankAccount account, QWidget *parent = nullptr);
    Deposit(QWidget *parent = nullptr);
    ~Deposit();
    //explicit Deposit(QWidget *parent = nullptr);

    BankAccount *m_account;
    DatabaseConnection *m_db;

//explicit Deposit(QWidget *parent = nullptr);//burasıı
//    ~Deposit();

private slots:
    void on_pushButton_Cancel_Deposit_clicked();

    void on_pushButton_Back_Deposit_clicked();

    void on_pushButton_Confirm_Deposit_clicked();

private:
//    void updateBalance(int depositAmount); GPTNİN 2YE AYIRDIĞI KOD+++++++++++++++
//    void updateBalanceInDatabase(int newBalance);
    Ui::Deposit *ui;   
};

#endif // DEPOSIT_H
