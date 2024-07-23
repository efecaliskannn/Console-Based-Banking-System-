#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class login_database;
}

class login_database : public QWidget
{
    Q_OBJECT

private:
    DatabaseConnection();
    bool Connect();
    void Disconect();



public:

    explicit login_database(QWidget *parent = nullptr);
    ~login_database();

private:
    Ui::login_database *ui;
};

#endif // DATABASE_CONNECTION_H
