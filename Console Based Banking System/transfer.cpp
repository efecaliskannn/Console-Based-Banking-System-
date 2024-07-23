#include "transfer.h"
#include "ui_transfer.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

Transfer::Transfer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::on_pushButton_Cancel_Transfer_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Efe Caliskan","Are You sure to close the application?",QMessageBox::Yes |  QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void Transfer::on_pushButton_Back_Transfer_clicked()
{
    this->close();
    MainPage *mainpage = new MainPage();
    mainpage->show();
}





void Transfer::on_pushButton_Confirm_Transfer_clicked()

{
    QString accountEmail = m_account->getEmail();
    QString senderEmail = ui->lineEdit_Transfer_From->text().toLower();
    QString receiverEmail = ui->lineEdit_Transfer_To->text().toLower();
    QString amountStr = ui->lineEdit_Transfer->text();
    bool ok;
    int amount = amountStr.toInt(&ok);

    qDebug() << "Sender Email: " << senderEmail;

    qDebug() << "Account Email: " << accountEmail;

    if (senderEmail != accountEmail)
    {
        QMessageBox::information(this, "Error", "Sender email must match your logged-in email.");
        qDebug() << "Sender email must match your logged-in email.";
        return;
    }

    if (senderEmail.toLower() == receiverEmail.toLower())
    {
        QMessageBox::information(this, "Error", "Sender and receiver cannot be the same.");
        return;
    }


    if (!ok) {
        QMessageBox::information(this, "Error", "Please enter a valid integer amount.");
        return;
    }

    if (amount <= 0) {
        QMessageBox::information(this, "Error", "Transfer amount must be greater than zero.");
        return;
    }


    const int transferLimit = 100000;
    if (amount > transferLimit)
    {
        QMessageBox::information(this, "Error", "Transfer amount exceeds the limit.");
        return;
    }
    // Veritabanı bağlantısını açın
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();
    if (!dbConnection.open())
    {
        qDebug() << "Database connection error";
        return;
    }

    // Gönderen hesabın bakiyesini kontrol edin
    QSqlQuery senderQuery(dbConnection.getDatabase());
    senderQuery.prepare("SELECT Balance FROM login_table WHERE Email = :email");
    senderQuery.bindValue(":email", senderEmail);

    if (!senderQuery.exec())
    {
        qDebug() << "Database error during balance retrieval: " << senderQuery.lastError().text();
        dbConnection.close();
        return;
    }

    if (senderQuery.next())
    {
        int senderBalance = senderQuery.value(0).toInt();

        if (senderBalance < amount)
        {
            QMessageBox::information(this, "Error", "Insufficient balance in sender's account.");
            qDebug() << "Insufficient balance in sender's account.";
            dbConnection.close();
            return;
        }

        // Alıcı hesabın bakiyesini kontrol edin
        QSqlQuery receiverQuery(dbConnection.getDatabase());
        receiverQuery.prepare("SELECT Balance FROM login_table WHERE Email = :email");
        receiverQuery.bindValue(":email", receiverEmail);

        if (!receiverQuery.exec())
        {
            qDebug() << "Database error during balance retrieval for receiver: " << receiverQuery.lastError().text();
            dbConnection.close();
            return;
        }

        if (receiverQuery.next())
        {
            int receiverBalance = receiverQuery.value(0).toInt();

            // Gönderen hesaptan para çekin
            int newSenderBalance = senderBalance - amount;
            QSqlQuery updateSenderQuery(dbConnection.getDatabase());
            updateSenderQuery.prepare("UPDATE login_table SET Balance = :balance WHERE Email = :email");
            updateSenderQuery.bindValue(":email", senderEmail);
            updateSenderQuery.bindValue(":balance", newSenderBalance);

            if (!updateSenderQuery.exec())
            {
                qDebug() << "Database error during sender's balance update: " << updateSenderQuery.lastError().text();
                dbConnection.close();
                return;
            }

            // Alıcı hesaba para ekle
            int newReceiverBalance = receiverBalance + amount;
            QSqlQuery updateReceiverQuery(dbConnection.getDatabase());
            updateReceiverQuery.prepare("UPDATE login_table SET Balance = :balance WHERE Email = :email");
            updateReceiverQuery.bindValue(":email", receiverEmail);
            updateReceiverQuery.bindValue(":balance", newReceiverBalance);

            if (!updateReceiverQuery.exec())
            {
                qDebug() << "Database error during receiver's balance update: " << updateReceiverQuery.lastError().text();
                dbConnection.close();
                return;
            }

            // Transfer işlemi başarılı, veritabanı bağlantısını kapatın
            dbConnection.close();

            QMessageBox::information(this, "Success", "Transfer successful.");
        }
        else
        {
            qDebug() << "Receiver account not found in the database.";
            dbConnection.close();
        }
    }
    else
    {
        qDebug() << "Sender account not found in the database.";
        dbConnection.close();
    }

}

