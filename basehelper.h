#ifndef BASEHELPER_H
#define BASEHELPER_H

#include <QObject>

class BaseHelper : public QObject
{
    Q_OBJECT
public:
    explicit BaseHelper(QObject *parent = 0);

    virtual void select(){}
    virtual void remove(){}
    virtual void append(QWidget *widget = nullptr){}
};

#endif // BASEHELPER_H
