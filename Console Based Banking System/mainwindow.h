#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "bankaccount.h"
#include <QMainWindow>
#include <QMessageBox>
#include "mainpage.h"
#include "databaseconnection.h"
#include "deposit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Cancel_clicked();


    void on_pushButton_Login_Register_clicked();

private:
    Ui::MainWindow *ui;
    QString m_account;
    DatabaseConnection *m_db;
};
#endif // MAINWINDOW_H
