#include "databasehelper.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QCoreApplication>
#include <QNetworkInterface>
#include <QHostInfo>
#include <QUuid>

#include <QDebug>

//#include "common.h"

//#include <windows.h>

//#include <odbcinst.h>

QSqlDatabase DataBaseHelper::db = QSqlDatabase();
DataBaseHelper::DataBaseHelper()
{

}

void DataBaseHelper::init()
{
    createConnection();
}

void DataBaseHelper::createODBC()
{

//    SQLHENV henv;
//    SQLHDBC hdbc;

//    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
//    ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

//    ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

//    SQLConfigDataSource(NULL, ODBC_ADD_DSN, "SQL Server",
//                              ("DSN=360HIS\0"
//                              "Server=192.168.0.247\0"
//                              "Database=360HIS\0"
//                              "UID=sa\0"
//                              "PWD=zaq12wsx@@\0"
//                              "Trusted_Connection=no\0"));

}

bool DataBaseHelper::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");

    QString name = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;")
            .arg("192.168.0.247").arg("360HIS").arg("sa").arg("zaq12wsx@@");

    db.setDatabaseName(name);

    if(!db.open()){
        qDebug() << "can't connect the database.";
        return false;
    }

    return true;
}

QSqlDatabase DataBaseHelper::DataBase()
{
    return db;
}

int DataBaseHelper::login(QString username, QString password)
{
    QSqlQuery query(db);
    QString cmd = "select * from device where "
                  "username = '" + username +"' and password = '" + password + "'";

    query.exec(cmd);

    if(query.next()){
//        _CUR_USER.id = query.value(0).toInt();
//        _CUR_USER.type = query.value(1).toInt();
//        strcpy(_CUR_USER.username,query.value(2).toString().toStdString().data());
//        strcpy(_CUR_USER.password,query.value(3).toString().toStdString().data());
//        strcpy(_CUR_USER.ipaddress,query.value(4).toString().toStdString().data());
//        return _CUR_USER.id;
    }else {
        qDebug() << query.lastError().text();
    }
    return -1;
}

QString DataBaseHelper::Mac()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();
    int nCnt = nets.count();
    QString strMacAddr = "";
    for (int i = 0; i < nCnt; i++)
    {
        if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}

QString DataBaseHelper::HostName()
{
    return QHostInfo::localHostName();
}
