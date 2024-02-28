#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void testCurrent()
{
    qInfo() << QDir::currentPath();

    QDir dir;
    qInfo() << dir.absolutePath();
}

void testList(QString path, bool recursive = false)
{
    QDir root(path);

    if (!root.exists())
    {
        qWarning() << "Path not found" << path;
        return;
    }

    QFileInfoList list = root.entryInfoList(QDir::NoDotAndDotDot | QDir::Filter::AllEntries);

    foreach(QFileInfo fi, list)
    {
        qInfo() << "----------------";
        qInfo() << "Name" << fi.fileName();
        qInfo() << "Path" << fi.filePath();
        qInfo() << "Absolute" << fi.absoluteFilePath();
        qInfo() << "Created" << fi.birthTime().toString();
        qInfo() << "Modified" << fi.lastModified();
        qInfo() << "Size" << fi.size();

        if (recursive && fi.isDir())
        {
            testList(fi.absoluteFilePath());
        }
    }
}

void testModify(QDir root)
{
    if (root.exists("qt_test"))
    {
        qInfo() << "Folder allready exists";
        return;
    }

    if (root.mkdir("qt_test"))
    {
        QDir dir("qt_test");
        qInfo() << "Created" << dir.absolutePath();

        if (root.rename("qt_test", "qt6_test"))
        {
            qInfo() << "Renamed" << dir.absolutePath();
            // Is now NULL
            qInfo() << "Test" << dir.exists();

            if (root.rmdir("qt6_test"))
            {
                qInfo() << "Removed directory" << dir.absolutePath();
            }
            else
            {
                qInfo() << "Remove failed!";
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // testCurrent();
    // testList(QDir::currentPath());
    testModify(QDir::current());

    return a.exec();
}
