#include <QCoreApplication>
#include <QTimer>

#include "child.h"

Child* getChild(QObject* parent)
{
    return new Child(parent);
}

Child* getChild()
{
    return new Child();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);

    Child* dog = getChild(&a);
    dog->setObjectName("Dog");

    Child* cat = getChild();
    cat->setObjectName("Cat");
    cat->setParent(dog);

    int ret = a.exec();
    qInfo() << "Exit code:" << ret;
    return ret;
}
