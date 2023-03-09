#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <QObject>
//#include "common.h"

class QSqlDatabase;

class DataBaseHelper: public QObject
{
public:
    DataBaseHelper();
    void init();
    void createODBC();

    static bool createConnection();

    static QSqlDatabase DataBase();
    int login(QString username,QString password);

private:

    QString Mac();
    QString HostName();

    static QSqlDatabase db;

//    _CurUser _user;
};

#endif // DATABASEHELPER_H
