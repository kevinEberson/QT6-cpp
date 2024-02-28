#include <QCoreApplication>
#include <QTextStream>

#include "inventory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Inventory inventory;

    qInfo() << "Available commands:";
    qInfo() << "add <name> <quantity>";
    qInfo() << "remove <name> <quantity>";
    qInfo() << "save";
    qInfo() << "load";
    qInfo() << "list";
    qInfo() << "quit";

    QTextStream stream(stdin);

    while(true)
    {
        qInfo() << "Enter a command";
        QString line = stream.readLine();
        QStringList list = line.split(" ");

        if(list.size() < 1)
        {
            break;
        }

        QString command = list.at(0).toLower();

        if(command == "quit")
        {
            return 0;
        }
        else if(command == "list")
        {
            inventory.list();
        }
        else if(command == "load")
        {
            inventory.load();
        }
        else if(command == "save")
        {
            inventory.save();
        }
        else if(command == "add" || command == "remove")
        {
            if(list.size() < 3)
            {
                qWarning() << "Not enough arguments";
                break;
            }

            QString name = list.at(1);
            bool canConvert;
            int quantity = list.at(2).toInt(&canConvert);

            if (!canConvert || quantity < 1)
            {
                qWarning() << "Invalid quantity";
            }

            if (command == "add")
            {
                inventory.add(name, quantity);
            }
            else
            {
                inventory.remove(name, quantity);
            }
        }
    }

    inventory.save();

    return 0;
}
