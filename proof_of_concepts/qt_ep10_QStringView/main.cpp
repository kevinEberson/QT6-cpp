#include <QCoreApplication>

void readName(QString name)
{
    name.insert(0, "Mr.");
    qInfo() << "Changed" << name;
}

void readOnly(QStringView name)
{
    qInfo() << "name" << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstname = "Kevin";
    QString lastname = "E";

    // Issues with copying and modifying
    // readName(firstname);
    qInfo() << "Original" << firstname;

    // Readonly, no copy
    qInfo() << "name" << firstname.data() << firstname;
    readOnly(firstname);

    // Parsing
    QString fullname = firstname + " " + lastname;

    foreach(QStringView part, QStringView(fullname).split(QChar(' ')))
    {
        qInfo() << "Part" << part;

        if (part.startsWith(QStringView(firstname), Qt::CaseInsensitive))
        {
            qInfo() << "~First name detected!~";
            readOnly(QStringView(firstname).mid(0,2));
        }
    }

    return a.exec();
}
