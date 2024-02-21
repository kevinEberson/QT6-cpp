#include <QCoreApplication>

#include <QScopedPointer>
#include <QSharedPointer>

#include "test.h"

void testScope()
{
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
}

void work(QSharedPointer<Test> ptr)
{
    ptr->message("Working");
}

void finish(QSharedPointer<Test> ptr)
{
    ptr->message("Finished");
}

void step(QSharedPointer<Test> ptr)
{
    ptr->message("Stepping");

    for (int i = 0; i < 3; ++i)
    {
        work(ptr);
    }

    finish(ptr);
}

void testShared(Test* test)
{
    QSharedPointer<Test> ptr(test);
    ptr->message("Starting");
    step(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // testScope();
    testShared(new Test());

    return a.exec();
}
