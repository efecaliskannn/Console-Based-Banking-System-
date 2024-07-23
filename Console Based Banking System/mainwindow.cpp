#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "register_screen.h"
#include "databaseconnection.h"
#include <QMessageBox>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = new DatabaseConnection(); // DatabaseConnection nesnesi oluşturun
    if (!m_db->Connect()) {
        qDebug() << "Database connection error";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    m_db->Disconnect();
    //    delete m_db;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString email = ui->lineEdit_User_Name->text();
    QString password = ui->lineEdit_Password->text();


    if (email.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Email or Password is invalid");
        return; // Boş alan varsa işlemi durdur
    }


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/efe/database/database.db");

    if (!db.open()) {
        qDebug() << "Database connection error";
        return;
    }

    QSqlQuery query(db);

    if (query.exec("SELECT * FROM login_table WHERE Email = '"+email+"' and  Password = '"+password+"'"))
    {
        qDebug() << "Query executed" << Qt::endl;
        int c = 0;
        while (query.next()) ++c;

        if (c >= 1)
        {
            QMessageBox::information(this, "Info", "Login Successful");

            this->close();
            MainPage *mainpage = new MainPage();
            mainpage->show();
        }
        else
        {
            QMessageBox::information(this , "Info" , "Can not login");
            //            m_db->Disconnect();
            db.close();
            QSqlDatabase::removeDatabase(db.connectionName());
            return;
        }
        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());
    }

    m_account = email;

    //    m_db->Disconnect();
    //     QSqlDatabase::removeDatabase(m_db->getConnectionName());

}
//{
//    QString email =ui->lineEdit_User_Name->text();
//    QString password = ui->lineEdit_Password->text();

//    if (email.isEmpty() || password.isEmpty())
//    {
//        QMessageBox::warning(this, "Error", "Email or Password is invalid");
//        return; // Boş alan varsa işlemi durdur
//    }

//   DatabaseConnection con; ++++++++++++++++++++++++++++++
//    if (con.Connect())++++++++++++++++++++++++++++++++++
//    DatabaseConnection connection;
//    if (!connection.Connect()){
//        qDebug() << "Database connection error";
//        return;

//        qDebug() << "Connected" << Qt::endl;
//    }

//    QSqlQuery query;


//    if ( query.exec("SELECT * FROM login_table WHERE Email = '"+email+"' and  Password = '"+password+"'"))
//    {
//        qDebug() << "Query executed" << Qt::endl;
//        int c = 0;
//        while (query.next()) ++c;

//        if ( c >= 1)
//        {
//            QMessageBox::information(this, "Info", "Login Successful");

//            this->close();
//            MainPage *mainpage = new MainPage();
//            mainpage->show();
//        }
//        else
//        {
//            QMessageBox::information(this , "Info" , "Can not login");
//            connection.Disconnect();
//            return;
//        }
//    }

//    m_account = email;

//    connection.Disconnect();
//}


















//void MainWindow::on_pushButton_Login_clicked()
//{
//    QString UserName = ui->lineEdit_User_Name->text();
//    QString Password = ui->lineEdit_Password -> text();
//    if ((UserName == "efecaliskan" && Password == "efe123")  ||  (UserName =="efecaliskan1"  &&  Password =="efe1234"))
//    {
//        QMessageBox::information(this , "Efe Caliskan" , "Login Succes.");
//        this->hide();
//        MainPage *mainpage = new MainPage();
//        mainpage->show();
//    }
//    else
//    {
//        QMessageBox::warning (this , "Efe Caliskan","Please Enter Valid Username Or Password");
//    }





void MainWindow::on_pushButton_Cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void MainWindow::on_pushButton_Login_Register_clicked()
{
    this->close();
    register_screen *registerscreen = new register_screen();
    registerscreen->show();
}



//    DatabaseConnection con;


//  if (con.Connect()){
//    qDebug() << "Connected" << endl;
//    ui->statusLabel->setText("Connect");
//}


