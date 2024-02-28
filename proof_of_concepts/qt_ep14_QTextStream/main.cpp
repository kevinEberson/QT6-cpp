#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    // IO
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name:" << Qt::endl;
    // qout.flush();

    QString name = qin.readLine();
    qout << "Hi " << name << "!\n";
    qout << "Enter your age:\n";
    qout.flush();

    bool canConvert;
    int age = qin.readLine().toInt(&canConvert);

    if (canConvert)
    {
        qout << "You are " << age << " years old.";
    }
    else
    {
        qout << "Next time, read the directions please...";
    }

    qout.flush();

    return a.exec();
}
