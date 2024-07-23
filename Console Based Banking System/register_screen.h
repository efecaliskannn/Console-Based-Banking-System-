#ifndef REGISTER_SCREEN_H
#define REGISTER_SCREEN_H
#include "databaseconnection.h"
#include "bankaccount.h"
#include <QWidget>

namespace Ui {
class register_screen;
}

class register_screen : public QWidget
{
    Q_OBJECT

public:
    explicit register_screen(QWidget *parent = nullptr);
    ~register_screen();

private slots:
    void on_pushButton_Register_Confirm_clicked();

    void on_pushButton_Register_Cancel_clicked();

    void on_pushButton_Back_Balance_clicked();

private:
    Ui::register_screen *ui;
    BankAccount m_account;
    bool Open();
    void Close();
    DatabaseConnection *m_db;
};

#endif // REGISTER_SCREEN_H
