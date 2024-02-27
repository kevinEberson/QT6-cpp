#include <QCoreApplication>
#include <QRandomGenerator>
#include <QSharedPointer>

#include "test.h"

QList<int> getNumbers()
{
    QList<int> list;

    int listLength = QRandomGenerator::global()->bounded(3,10);

    for (int i = 0; i < listLength; ++i)
    {
        list.append(QRandomGenerator::global()->bounded(1, 100));
    }

    return list;
}

void testNumbers()f
{
    QList<int> list = getNumbers();
    qInfo() << list;

    qInfo() << "Lenght" << list.length();
    qInfo() << "Count" << list.count();
    qInfo() << "Size" << list.size();

    foreach (int i, list)
    {
        qInfo() << i;
    }
}

void testSearch()
{
    QList<int> list = getNumbers();
    int item = 999;

    list.insert(0, item);
    list.insert(3, item);
    list.append(item);

    for (int i = 0; i < list.length(); ++i)
    {
        qInfo() << i << "=" << list.at(i);
    }

    // First & last element
    qInfo() << "First" << list.indexOf(item);
    qInfo() << "Last" << list.lastIndexOf(item);

    int pos = list.indexOf(item);

    do
    {
        qInfo() << "At" << pos;
        pos = list.indexOf(item, pos + 1);
    } while (pos > -1);

    qInfo() << "Contains" << list.contains(item);
    QList<int> items = list.sliced(1, 3);
    qInfo() << list;
    qInfo() << items;


}

void testModifying()
{
    QList<int> list = getNumbers();

    list[0] = 1000;
    list.append(99);

    list.insert(0, 55);

    for (int i = 0; i < 10; ++i)
    {
        list.insert(0, 255);
    }


    qInfo() << "Lenght" << list.length();
    list.removeAt(0);
    qInfo() << "RemoveAt" << list.length();
    list.removeOne(255);
    qInfo() << "RemoveOne" << list.length();
    list.removeAll(255);
    qInfo() << "RemoveAll" << list.length();

    for (int i = 0; i < list.size(); ++i)
    {
        qInfo() << i << "=" << list.at(i);
    }

}

void testDeleteAll()
{
    QList<Test*> list;

    for (int i = 0; i < 5; ++i)
    {
        list.append(new Test());
    }

    qInfo() << "Cleanup";
    qDeleteAll(list);
    list.clear();
    qInfo() << list.length();
}

void testSmart()
{
    QList<QSharedPointer<Test>> list;

    for (int i = 0; i < 5; ++i)
    {
        QSharedPointer<Test> item(new Test);
        list.append(item);
    }

    qInfo() << "Remove first";
    list.removeFirst();

    qInfo() << "Clear";
    list.clear();
    qInfo() << list.length();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // testNumbers();
    // testModifying();
    // testSearch();
    // testDeleteAll();
    testSmart();

    return a.exec();
}
