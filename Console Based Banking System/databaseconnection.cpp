

#include "databaseconnection.h"
#include <qdebug.h>
DatabaseConnection::DatabaseConnection()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("/home/efe/database/database.db");
}

bool DatabaseConnection::Connect()
{
    if (dataBase.open())
        return true;
    else
        return false;
}

void DatabaseConnection::Disconnect()
{
    dataBase.close();

}

QSqlDatabase DatabaseConnection::getDatabase()
{
    return dataBase;
}

QString DatabaseConnection::getConnectionName() const
{
    return getConnectionName();
}

//88888888888888888888888888888888888888888888888888888888888
//#include "databaseconnection.h"
//#include <QDebug>

//DatabaseConnection::DatabaseConnection()
//{
//    // Özel bağlantı adı ile veritabanı bağlantısı oluşturuluyor
//    dataBase = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
//    dataBase.setDatabaseName("/home/efe/database/database.db");
//}

//bool DatabaseConnection::Connect()
//{
//    if (dataBase.open())
//    {
//        qDebug() << "Database connected";
//        return true;
//    }
//    else
//    {
//        qDebug() << "Error: Connection with database failed";
//        return false;
//    }
//}

//void DatabaseConnection::Disconnect()
//{
//    dataBase.close();
//    qDebug() << "Database disconnected";
//}
//88888888888888888888888888888888888888888888888888888888888888888888888
//#include "databaseconnection.h"
//#include <QDebug>

//DatabaseConnection::DatabaseConnection()
//{
//    dataBase = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
//    dataBase.setDatabaseName("/home/efe/database/database.db");
//}

//bool DatabaseConnection::Connect()
//{
//    if (!dataBase.isOpen() && dataBase.open())
//    {
//        qDebug() << "Database connected";
//        return true;
//    }
//    else
//    {
//        qDebug() << "Error: Connection with database failed";
//        return false;
//    }
//}

//void DatabaseConnection::Disconnect()
//{
//    if (dataBase.isOpen())
//    {
//        dataBase.close();
//        qDebug() << "Database disconnected";
//    }
//    else
//    {
//        qDebug() << "Error: Database is not open";
//    }
//}

