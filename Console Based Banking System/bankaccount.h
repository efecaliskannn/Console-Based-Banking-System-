#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QString>
#include <QMainWindow>
#include "bankaccount.h"
#include "databaseconnection.h"

class BankAccount
{

public:

    BankAccount();

    QString m_name;
    QString m_password;
    QString m_email;
    QString m_phone;

    // ... Diğer üye değişkenler ve işlevler

    void setBalance(int balance);
    int getBalance();

    void setName(QString name);
    QString getName();

    void setPassword(QString password);
    QString getPassword();

    void setEmail(QString email);
    QString getEmail();

    void setPhone(QString phone);
    QString getPhone();
private:
    int m_balance;
};
#endif // BANKACCOUNT_H
