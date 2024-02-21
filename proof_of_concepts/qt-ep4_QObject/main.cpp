#include <QCoreApplication>


#include "test.h"

int main(int argc, char *argv[])
{
    // Base class
    QCoreApplication a(argc, argv);

    Test test;

    // Connect singal and slot
    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    test.do_stuff();

    return a.exec();
}
