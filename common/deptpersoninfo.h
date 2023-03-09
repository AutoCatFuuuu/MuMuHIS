#ifndef DEPTPERSONINFO_H
#define DEPTPERSONINFO_H

#include "basehelper.h"
#include <QTableView>
#include <QSqlTableModel>

class DeptPersonInfo : public BaseHelper
{
public:
    explicit DeptPersonInfo(QObject *parent = 0);

    void init(QTableView* view);
    void select();
    void remove();
    void append(QWidget *parent = nullptr);

    static DeptPersonInfo* instance();

private:
    QSqlTableModel *_model;
    QTableView *_view;

    static DeptPersonInfo *_instance;
};

#endif // DEPTPERSONINFO_H
