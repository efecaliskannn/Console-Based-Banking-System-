#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainpage.h"
#include "bankaccount.h"
#include "databaseconnection.h"

namespace Ui {
class Withdraw;
}

class Withdraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();
    DatabaseConnection *m_db;


private slots:
    void on_pushButton_Cancel_Withdraw_clicked();

    void on_pushButton_Back_Withdraw_clicked();

    void on_pushButton_Confirm_Withdraw_clicked();

private:
    Ui::Withdraw *ui;
};

#endif // WITHDRAW_H
