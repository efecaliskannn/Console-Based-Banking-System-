#ifndef BALANCE_H
#define BALANCE_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainpage.h"
#include "bankaccount.h"
#include "databaseconnection.h"

namespace Ui {
class Balance;
}

class Balance : public QMainWindow
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = nullptr);
    ~Balance();
     void showNewBalance(int newBalance);// yeni ekledim

    DatabaseConnection *m_db;




private slots:
    void on_pushButton_Cancel_Balance_clicked();


    void on_pushButton_Back_Balance_clicked();


private:
    Ui::Balance *ui;
};

#endif // BALANCE_H
