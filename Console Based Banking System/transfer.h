#ifndef TRANSFER_H
#define TRANSFER_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainpage.h"
#include "bankaccount.h"
#include "databaseconnection.h"

namespace Ui {
class Transfer;
}

class Transfer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    ~Transfer();
    DatabaseConnection *m_db;



private slots:
    void on_pushButton_Cancel_Transfer_clicked();

    void on_pushButton_Back_Transfer_clicked();

private:
    Ui::Transfer *ui;
};

#endif // TRANSFER_H
