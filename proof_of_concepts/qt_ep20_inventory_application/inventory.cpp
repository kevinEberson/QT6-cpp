#include "inventory.h"

Inventory::Inventory(QObject *parent)
    : QObject{parent}
{
    load();
}

void Inventory::add(QString name, int quantity)
{
    if (m_items.contains(name))
    {
        m_items[name] += quantity;
    }
    else
    {
        m_items.insert(name, quantity);
    }
}

void Inventory::remove(QString name, int quantity)
{
    if (m_items.contains(name))
    {
        m_items[name] -= quantity;
        if (m_items.value(name) < 0)
        {
            m_items.remove(name);
        }

        qInfo() << "Removed" << name;
    }
    else
    {
        qWarning() << "No such item found!";
    }
}

void Inventory::list()
{
    qInfo() << "Items:" << m_items.size();

    foreach (QString key, m_items.keys())
    {
        qInfo() << key << " = " << m_items.value(key);
    }
}

void Inventory::save()
{
    QFile file("inventory.txt");

    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Could not save file:" << file.errorString();
        return;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_6);

    int length = m_items.size();
    stream << length;

    qInfo() << "Number of items to save:" << length;

    foreach (QString key, m_items.keys())
    {
        qInfo() << "Saving:" << key;
        stream << key;
        stream << m_items.value(key);
    }

    file.close();
    qInfo("Done saving.");

    return;
}

void Inventory::load()
{
    QFile file("inventory.txt");

    if(!file.exists())
    {
        qWarning() << "File not found!";
        return;
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Could not open file:" << file.errorString();
        return;
    }

    QDataStream stream(&file);

    if(stream.version() != QDataStream::Qt_6_6)
    {
        qCritical() << "Wrong data stream version!";
        file.close();
        return;
    }

    m_items.clear();

    int max;
    stream >> max;

    qInfo() << "Number of items to load:" << max;

    for (int i = 0; i < max; ++i)
    {
        QString key;
        int quantity;

        stream >> key;
        stream >> quantity;

        m_items.insert(key, quantity);
    }

    file.close();
    qInfo("Done loading.");

    return;
}
