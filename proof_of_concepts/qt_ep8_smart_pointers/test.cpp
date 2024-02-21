#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructor called" << parent;
}

Test::~Test()
{
    qInfo() << "Deconstructor called" << parent();
}

void Test::message(QString value)
{
    qInfo() << this << value;
}
