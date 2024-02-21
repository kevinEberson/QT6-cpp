#include "test.h"
#include <QDebug>

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::do_stuff()
{
    qInfo() << "Executing code...";
    emit close();
}
