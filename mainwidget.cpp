#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    _deptPersonInfoW = 0;
    _tbnList = ui->toolBox->findChildren<QToolButton*>();

    foreach (QToolButton *tbn, _tbnList) {
        connect(tbn,&QToolButton::clicked,this,&MainWidget::toolBoxTbnClicked);
    }

    connect(ui->deptPersonInfoBtn,&QToolButton::clicked,this,&MainWidget::deptPersonInfoClicked);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::toolBoxTbnClicked()
{
    QToolButton *tbn = (QToolButton*)sender();

    QString str = tbn->text();

    int count = ui->tabWidget->count();

    for(int i = 0;i < count;++i) {
        if(ui->tabWidget->tabText(i) == str) {
            ui->tabWidget->setCurrentIndex(i);
            break;
        }
    }
}

void MainWidget::deptPersonInfoClicked()
{
    if(!_deptPersonInfoW) {
        _deptPersonInfoW  = new ShowWidget;
        _deptPersonInfo = new DeptPersonInfo;
    }
    ui->tabWidget->addTab(_deptPersonInfoW,"人员信息");
    _deptPersonInfo->init(_deptPersonInfoW->view());
    _deptPersonInfo->select();
}
