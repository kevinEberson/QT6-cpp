#include <QCoreApplication>
#include <QDebug>

#include "cat.h"

// Pass by reference
void print_address (Cat &cat)
{
    qInfo() << "Addr " << &cat;
}

void print_object (Cat *cat)
{
    qInfo() << "Ptr " << cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat kitty;
    // obj name can be the same, address not.
    kitty.setObjectName("Mittens");

    print_address(kitty);
    print_object(&kitty);


    return a.exec();
}
