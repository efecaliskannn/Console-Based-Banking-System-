#include "register_screen.h"
#include "ui_register_screen.h"
#include "mainwindow.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include "databaseconnection.h"
#include <QMessageBox>
#include <QValidator>
#include <QRegExp>
#include <QRegularExpression>

register_screen::register_screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::register_screen)
{
    ui->setupUi(this);
}

register_screen::~register_screen()
{
    delete ui;
}

//void register_screen::on_pushButton_Register_Confirm_clicked()++++++++++++++++++++++++++++++++++++
//{
//    QString name = ui->lineEdit_Register_Name->text();
//    QString email = ui->lineEdit_Register_Email->text();
//    QString password = ui->lineEdit_Register_Password->text();
//    QString phone = ui->lineEdit_Register_Phone->text();


//    if (name.isEmpty()) {
//        QMessageBox::warning(this, "Error", "Invalid or missing Name!");
//        return;
//    }
//    if (password.isEmpty()) {
//        QMessageBox::warning(this, "Error", "Invalid or missing Password!");
//        return;
//    }
//    if (email.isEmpty()) {
//        QMessageBox::warning(this, "Error", "Invalid or missing Email!");
//        return;

//    }

//    if (!email.contains('@')) {
//        QMessageBox::warning(this, "Error", "Invalid email format!");
//        return;}



//    if (phone.isEmpty()) {
//        QMessageBox::warning(this, "Error", "Invalid or missing Phone!");
//        return;

//    }
//    QRegularExpression phoneRegex("^\\d{11,11}$"); // En fazla 11 haneli ve sadece sayılardan oluşmalı
//    QRegularExpressionValidator validator(phoneRegex, this);
//    int pos = 0;
//    if (validator.validate(phone, pos) != QValidator::Acceptable) {
//        QMessageBox::warning(this, "Error", "Phone number must be 11 digits and only numbers!");
//        return;
//    }

// Telefon alanı için sadece sayı girişini sağlayan bir QValidator oluşturulur
//    QRegExp rx("\\d*"); // Sadece sayıları kabul etmek için regular expression
//    QValidator *validator = new QRegExpValidator(rx, this);++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    ui->lineEdit_Register_Phone->setValidator(validator);


//    if (name.isEmpty() || email.isEmpty() || password.isEmpty() || phone.isEmpty()) {
//        QMessageBox::warning(this, "Error", "Please fill in the blanks");
//        return; // Boş alan varsa işlemi durdur
//    }        ++++++++++++ BOŞ KUTUCUKLARI DOLDURMASI İÇİN UYARI VERİR FAKAT 1 TANESİ BİLE BOŞSA BOŞLUKLARI DOLDUR YAZIYOR.+++++++++++++


//    DatabaseConnection connection;

//    if (connection.Connect()){
//        qDebug() << "Connected" << Qt::endl;
//    }

//    QSqlQuery countQuery;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    if (countQuery.exec("SELECT COUNT(*) FROM login_table")) {
//        if (countQuery.next()) {
//            int accountCount = countQuery.value(0).toInt();
//            if (accountCount < 5) {
//                // Hesap sınırlaması aşılmamışsa yeni hesap oluştur
//                QSqlQuery query;
//                if ( query.exec("INSERT INTO login_table (Name, Email, Password, Phone, Balance) VALUES('"+name+"','"+email+"','"+password+"','"+phone+"' , 0)")){
//                    qDebug () << "Query executed" << Qt::endl;
//                }
//            } else {
//                // Hesap sınırlaması aşıldı, kullanıcıya bilgi ver
//                QMessageBox::warning(this, "Error", "Maximum account limit reached.");
//            }++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//        }
//    }




//if ( query.exec("INSERT INTO login_table (Name, Email, Password, Phone, balance) VALUES('"+name+"','"+email+"','"+password+"','"+phone+"', 0)")){
//qDebug () << "Query executed" << Qt::endl;}

//    QSqlQuery query;
//    if ( query.exec("INSERT INTO login_table (Name, Email, Password, Phone) VALUES('"+name+"','"+email+"','"+password+"','"+phone+"')")){
//        qDebug () << "Query executed" << Qt::endl;
//    }    +++++++++++++MAKSİMUM HESAP SINIRLAMASI İÇİN YORUMA ALDIM+++++++++++++

//    connection.Disconnect();++++++++++++++++++++++++++++++

//    this->close();
//    MainWindow *mainwindow = new MainWindow();
//    mainwindow->show();
//}++++++++++++++++++++++++++++++++++++++++++++++++++++++++



void register_screen::on_pushButton_Register_Confirm_clicked()


{
    QString name = ui->lineEdit_Register_Name->text();
    QString email = ui->lineEdit_Register_Email->text();
    QString password = ui->lineEdit_Register_Password->text();
    QString phone = ui->lineEdit_Register_Phone->text();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Error", "Invalid or missing Name!");
        return;
    }
    if (password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Invalid or missing Password!");
        return;
    }
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Error", "Invalid or missing Email!");
        return;
    }
    if (!email.contains('@')) {
        QMessageBox::warning(this, "Error", "Invalid email format!");
        return;
    }
    if (phone.isEmpty()) {
        QMessageBox::warning(this, "Error", "Invalid or missing Phone!");
        return;
    }

    QRegularExpression phoneRegex("^\\d{11,11}$");
    QRegularExpressionValidator validator(phoneRegex, this);
    int pos = 0;
    if (validator.validate(phone, pos) != QValidator::Acceptable) {
        QMessageBox::warning(this, "Error", "Phone number must be 11 digits and only numbers!");
        return;
    }

    //    DatabaseConnection connection;
    //    if (!connection.Connect()){
    //        qDebug() << "Database connection error";
    //        return;
    //    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/efe/database/database.db");
    if (!db.open()) {   
        qDebug() << "Database connection error";
        return;
    }
    QSqlQuery countQuery;
    if (countQuery.exec("SELECT COUNT(*) FROM login_table")) {
        if (countQuery.next()) {
            int accountCount = countQuery.value(0).toInt();
            if (accountCount >= 5) {
                QMessageBox::warning(this, "Error", "Maximum account limit reached.");
                db.close();
                QSqlDatabase::removeDatabase(db.connectionName());
                return;
            }
        }
    } else {
        qDebug() << "Database error: " << countQuery.lastError().text();
        //        m_db->Disconnect();
        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM login_table WHERE Name = :name");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec()) {
        if (checkQuery.next()) {
            QMessageBox::warning(this, "Error", "An account with the same name already exists.");
            db.close();
            QSqlDatabase::removeDatabase(db.connectionName());
            return;
        } else {
            QSqlQuery query;
            if (query.exec("INSERT INTO login_table (Name, Email, Password, Phone, Balance) VALUES('"+name+"','"+email+"','"+password+"','"+phone+"' , 0)")){
                qDebug () << "Query executed" << Qt::endl;
            } else {
                qDebug() << "Database error: " << query.lastError().text();
            }
        }
    }
    else
    {

        qDebug() << "Database error: " << checkQuery.lastError().text();
    }
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());


    BankAccount account;
    account.setName(name);
    account.setPassword(password);
    account.setEmail(email);
    account.setPhone(phone);
    account.setBalance(0);

    this->close();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();

    //    m_db->Disconnect();
    //     QSqlDatabase::removeDatabase(connectionName);

}










void register_screen::on_pushButton_Register_Cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }

}


void register_screen::on_pushButton_Back_Balance_clicked()
{
    this->close();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}

