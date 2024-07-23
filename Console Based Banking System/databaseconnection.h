#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include <QSqlDatabase>
#include "bankaccount.h"
class DatabaseConnection
{
public:

    DatabaseConnection();
    bool open();
    void close();
    bool Connect();
    void Disconnect();
    QSqlDatabase dataBase;


    QSqlDatabase getDatabase();
    QString getConnectionName() const;

//private:
//     QSqlDatabase dataBase;
//     QString connectionName;

};

#endif // DATABASECONNECTION_H
