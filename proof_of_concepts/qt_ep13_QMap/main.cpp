#include <QCoreApplication>
#include <QSharedPointer>
#include <QRandomGenerator>
#include <QMap>

#include "cat.h"

typedef QMap<QString, QSharedPointer<Cat>> catMap;


catMap getCats()
{
    catMap map;

    for (int i = 0; i < 5; ++i)
    {
        QSharedPointer<Cat> ptr(new Cat());

        ptr->setAge(QRandomGenerator::global()->bounded(1, 5));
        ptr->setName("Unknown");

        map.insert("pet" + QString::number(i), ptr);
    }

    return map;
}

void display(catMap &cats)
{
    foreach (QString key, cats.keys())
    {
        QSharedPointer<Cat> ptr = cats.value(key);
        qInfo() << key << ptr->name() << ptr->age() << ptr.data();
    }
}

void modifyCat(catMap &cats, QString key)
{
    if(cats.contains(key))
    {
        qInfo() << "Modifying:" << key;
        cats[key]->setAge(99);
        cats[key]->setName("Mittens");
        display(cats);
    }
}

void addCat(catMap &cats)
{
    qInfo() << "Adding cat";

    QSharedPointer<Cat> ptr(new Cat());

    ptr->setAge(1000);
    ptr->setName("Inmortal Mittens");
    cats.insert("Test cat", ptr);

    display(cats);
}

void findCat(catMap &cats, QString key)
{
    qInfo() << "Exists:" << cats.contains(key);

    auto iter = cats.find(key);

    if (iter != cats.end())
    {
        qInfo() << iter.key() << iter.value();
    }

    foreach (QString key, cats.keys())
    {
        qInfo() << "Key:" << key << "Value:" << cats.value(key);
    }

    foreach (QSharedPointer<Cat> value, cats.values())
    {
        qInfo() << "Value:" << value;
    }
}

void removeCat(catMap &cats, QString key)
{
    if (!cats.contains(key))
    {
        qWarning() << "Cat not found!";
        return;
    }

    cats.remove(key);
    display(cats);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QMap<QString, double> map;
    // map.insert(QString("Kevin"), 2.0);
    // qInfo() << map;
    // qInfo() << "Lucky number:" << map["Kevin"];

    catMap cats = getCats();
    // qInfo() << cats;

    display(cats);

    // modifyCat(cats, "pet1");
    addCat(cats);
    findCat(cats, "pet0");
    removeCat(cats, "Test cat");

    qInfo() << "Clearing list";
    cats.clear();

    return a.exec();
}
