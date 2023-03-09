#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>

class QTableView;

namespace Ui {
class ShowWidget;
}

class ShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowWidget(QWidget *parent = nullptr);
    ~ShowWidget();

    QTableView* view();
private:
    Ui::ShowWidget *ui;
};

#endif // SHOWWIDGET_H
