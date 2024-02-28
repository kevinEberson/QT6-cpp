#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

void writeToFile()
{
    QFile file("test.txt");
    if(!file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        qCritical() << "Error while openining file: " << file.errorString();
        return;
    }

    qInfo() << "Writing to test.txt";
    file.write(QByteArray("Hello World!"));
    file.flush();

    qInfo() << "Reading test.txt";
    file.seek(0);
    qInfo() << file.readAll();

    file.close();
}

bool writeFile(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        qCritical() << "Error while openining file: " << file.errorString();
        return false;
    }

    QTextStream stream(&file);

    for (int i = 0; i < 5; ++i)
    {
        stream << QString::number(i) << " Hello World!\r\n";
    }

    file.close();
    return true;
}

void readFile(QString filename)
{
    QFile file(filename);

    if(!file.exists())
    {
        qCritical() << "File:" << file.fileName() << "Not found!";
        return;
    }

    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qCritical() << "Error while openining file: " << file.errorString();
        return;
    }

    QTextStream stream(&file);
    // QString data = stream.readAll();

    while(!stream.atEnd())
    {
        qInfo() << stream.readLine();
    }

    file.close();
    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // writeToFile();
    writeFile("test.txt");
    readFile("test.txt");

    return a.exec();
}
