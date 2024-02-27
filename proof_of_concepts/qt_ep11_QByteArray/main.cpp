#include <QCoreApplication>

void stats(QByteArray &data)
{
    qInfo() << "Length" << data.length() << "Capacity" << data.capacity();
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray array;
    qInfo() << array;

    QByteArray data("Hello!");
    qInfo() << data;

    QByteArray buffer(10, '\t');
    qInfo() << buffer;

    QByteArray person(QString("Kevin").toLocal8Bit());
    qInfo() << person;

    // Sizing
    data.reserve(25);
    stats(data);

    data.resize(10);
    stats(data);

    data.truncate(8);
    stats(data);

    data.clear();
    stats(data);

    //modify data
    data.resize(5);
    data.fill('\x02');
    stats(data);

    data.replace(0, 99, QByteArray("Sweet"));
    stats(data);

    data.fill('*');
    data.insert(3, QByteArray("Hello World!"));
    stats(data);

    data.append('!');
    stats(data);

    data.remove(0, 3);
    stats(data);

    // Reading data

    int first = data.indexOf('*');
    int last = data.lastIndexOf('*');
    qInfo() << "Start" << first << "Last" << last;

    if(first > -1 && last > -1)
    {
        qInfo() << data.mid(first, (last - first) + 1);
    }

    data.clear();
    data.append("Kevin");

    for(int i = 0; i < data.length(); i++)
    {
        qInfo() << "At" << data.at(i);
    }

    foreach(char c, data)
    {
        qInfo() << "Char" << c;
    }

    foreach(auto item, data.split('e'))
    {
        qInfo() << "Item" << item;
    }

    // Encoding
    qInfo() << "Normal" << data;
    qInfo() << "Repeat" << data.repeated(3);

    data.append(QByteArray("\t\r\n"));
    data.insert(0, QByteArray("      \t\t\t"));
    qInfo() << "Normal" << data;
    qInfo() << "Trimmed" << data.trimmed();

    QByteArray hex = data.toHex();
    qInfo() << "Hex" << hex;
    qInfo() << "Decoded" << QByteArray::fromHex(hex);

    return a.exec();
}
