#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    // Creating
    QCoreApplication a(argc, argv);

    QString text("Hello World");
    qInfo() << text;

    QString name;
    name = "Kevin";
    qInfo() << name;

    int current = 2;
    int max = 14;
    QString status = QString("Processing file %1 of %2").arg(current).arg(max);
    qInfo() << status;

    // Reading chars
    for (int i = 0; i < text.length(); ++i)
    {
        QChar c = text.at(i);
        qInfo() << c;
    }

    // Compare & search
    qInfo() << "Compare" << text.compare("hello world", Qt::CaseSensitivity::CaseInsensitive);
    qInfo() << "Starts with" << text.startsWith("hello", Qt::CaseInsensitive);
    qInfo() << "Ends with" << text.endsWith("wold", Qt::CaseInsensitive);
    qInfo() << "Contains" << text.contains("world", Qt::CaseInsensitive);
    qInfo() << "Index" << text.indexOf("world", Qt::CaseInsensitive);

    // Mofifying and parsing
    text.append("\r\nHow are you?");
    qInfo() << "Escape" << text;

    text.append("\r\n<i>This</i> is HTML <br>");
    qInfo() << "HTML" << text.toHtmlEscaped();

    text.replace("?", "!");
    qInfo() << "Replace" << text;

    qInfo() << "Upper" << text.toUpper();
    qInfo() << "Lower" << text.toLower();
    qInfo() << "Mid" << text.mid(2, 5);

    QStringList list = text.split("\n");
    foreach(QString item, list)
    {
        qInfo() << "Item" << item.trimmed();
    }

    // Conversion
    std::cout << "std " << text.toStdString() << "\n";

    qInfo() << "UTF8" << text.toUtf8();
    qInfo() << "Base64" << text.toUtf8().toBase64();
    qInfo() << "Hex" << text.toUtf8().toHex();

    return a.exec();
}
