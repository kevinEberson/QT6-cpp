#include "child.h"

Child::Child(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructor called" << this->parent();
}

Child::~Child()
{
    foreach(QObject* child, children())
    {
        qInfo() << this << " - child - " << child;
    }

    qInfo() << this << "Deconstructor called" << this->parent();
}
