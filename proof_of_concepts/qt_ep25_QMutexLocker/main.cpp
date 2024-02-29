#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include <QDebug>

#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int count = 0;
    int nrOfThreads = 5;

    QMutex mutex;

    for (int i = 0; i < nrOfThreads; ++i)
    {
        Worker* worker = new Worker();
        worker->setCount(&count);
        worker->setMutex(&mutex);
        worker->setAutoDelete(true);

        QThreadPool::globalInstance()->start(worker);
    }

    QThreadPool::globalInstance()->waitForDone();
    qInfo() << "Count" << count;

    return a.exec();
}
