#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

void compileTime()
{
#ifdef Q_OS_WIN
    qInfo("This is Windows");
#endif
#ifdef Q_OS_LINUX
    qInfo("This is Linux");
#endif

}

void runTime()
{
    QSysInfo info;

    qInfo() << "Product name:" << info.prettyProductName();
    qInfo() << "Product type:" << info.productType();
    qInfo() << "Product version:" << info.productVersion();
    qInfo() << "Product hostname:" << info.machineHostName();
    qInfo() << "Product unique id:" << info.machineUniqueId();
    qInfo() << "Product current cpu arch:" << info.currentCpuArchitecture();
    qInfo() << "Product build cpu arch:" << info.buildCpuArchitecture();
    qInfo() << "Product buildABI:" << info.buildAbi();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    compileTime();
    runTime();

    return a.exec();
}
