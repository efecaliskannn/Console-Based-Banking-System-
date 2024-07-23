#include "bankaccount.h"
#include "databaseconnection.h"
BankAccount::BankAccount()
{
    m_balance = 0;
}

void BankAccount::setBalance(int balance)
{
    m_balance = balance;
}

int BankAccount::getBalance()
{
    return m_balance;
}

void BankAccount::setName(QString name)
{
    m_name = name;
}

QString BankAccount::getName()
{
    return m_name;
}

void BankAccount::setPassword(QString password)
{
    m_password = password;
}

QString BankAccount::getPassword()
{
    return m_password;
}

void BankAccount::setEmail(QString email)
{
    m_email = email;
}

QString BankAccount::getEmail()
{
    return m_email;
}

void BankAccount::setPhone(QString phone)
{
    m_phone = phone;
}

QString BankAccount::getPhone()
{
    return m_phone;
}
