#include "Database_Connection.h"
#include "ui_Database_Connection.h"

DatabaseConnection::login_database(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_database)
{
    ui->setupUi(this);
}

login_database::~login_database()
{
    delete ui;
}


bool DatabaseConnection::Connect();
