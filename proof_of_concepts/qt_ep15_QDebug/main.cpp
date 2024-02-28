#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>
#include <QTextStream>
#include <iostream>

#include "kitten.h"

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char* file = context.file ? context.file : "";
    const char* function = context.function ? context.function : "";

    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

void test()
{
    qDebug() << "test";
    qInfo() << "test";
    qWarning() << "test";
    qCritical() << "test";
    qFatal("Fatal message");

    Kitten kitty;
    kitty.meow();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream qin(stdin);
    std::cout << "Starting\n";
    bool running = true;

    do
    {
        std::cout << "Enter a command: start, stop, test or exit\n";
        QString cmd = qin.readLine();
        qInfo() << "You entered:" << cmd;

        if (cmd.toLower() == "start")
        {
            qInstallMessageHandler(myMessageOutput);
        }
        else if (cmd.toLower() == "stop")
        {
            qInstallMessageHandler(0);
        }
        else if (cmd.toLower() == "test")
        {
            test();
        }
        else if (cmd.toLower() == "exit")
        {
            running = false;
        }
        else
        {
            std::cout << "Unknown command\n";
        }


    } while (running);

    std::cout << "Exited with return code 0";

    return a.exec();
}
