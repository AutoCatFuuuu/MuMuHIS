#include "deptpersoninfo.h"

#include <QHeaderView>

DeptPersonInfo* DeptPersonInfo::_instance = nullptr;
DeptPersonInfo::DeptPersonInfo(QObject *parent) : BaseHelper(parent)
{
    _model = new QSqlTableModel(this);
    _view = nullptr;
}

void DeptPersonInfo::init(QTableView *view)
{
    _model->setTable("Pub_Employee");
//    _model->setFilter("name <> '默认'");
//    _model->setHeaderData(0,Qt::Horizontal,"ID");
//    _model->setHeaderData(1,Qt::Horizontal,"名称");

    _view = view;
    _view->setModel(_model);

//    _view->setColumnHidden(0,true);
//    _view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void DeptPersonInfo::select()
{
    _model->select();
}

void DeptPersonInfo::remove()
{
//    QModelIndexList list =  _view->selectionModel()->selectedRows();

//    if(list.size() > 0){
//        DataBaseHelper db;
//        foreach (QModelIndex index,list) {
//            int id = _model->index(index.row(),0).data().toInt();
//            db.delDepartment(id);
//        }
//        select();
//    }
}

void DeptPersonInfo::append(QWidget *parent)
{
//    int rowNum = _model->rowCount();

//    _model->insertRow(rowNum);

//    _view->edit(_model->index(rowNum,1));
//    _view->scrollToBottom();
}

DeptPersonInfo* DeptPersonInfo::instance()
{
    if(!_instance) {
        _instance = new DeptPersonInfo;
    }

    return _instance;
}
