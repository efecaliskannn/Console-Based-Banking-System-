#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QMessageBox>
#include "balance.h"
#include "withdraw.h"
#include "deposit.h"
#include "transfer.h"
#include "bankaccount.h"
#include "databaseconnection.h"


namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();
    DatabaseConnection *m_db;


private slots:
    void on_pushButton_Balance_clicked(); 

    void on_pushButton_Withdraw_clicked();

    void on_pushButton_Deposit_clicked();

    void on_pushButton_Transfer_clicked();

    void on_pushButton_Cancel2_clicked();

private:
    Ui::MainPage *ui;
    BankAccount *m_account;
   // DatabaseConnection *m_db;

    void openAndShow(QWidget *widgetToShow);
};

#endif // MAINPAGE_H
