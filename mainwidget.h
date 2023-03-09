#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "./common/deptpersoninfo.h"
#include "showwidget.h"

class QToolButton;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void toolBoxTbnClicked();
    void deptPersonInfoClicked();

private:
    Ui::MainWidget *ui;

    QList<QToolButton*> _tbnList;
    //QMap<int, QWidget*> _wMap;

    ShowWidget *_deptPersonInfoW;

    DeptPersonInfo *_deptPersonInfo;
};

#endif // MAINWIDGET_H
