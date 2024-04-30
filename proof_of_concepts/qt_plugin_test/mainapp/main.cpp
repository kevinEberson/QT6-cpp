#include <QCoreApplication>
#include <QPluginLoader>
#include <QDebug>
#include "../helloworldplugin/helloplugininterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString pluginPath = QCoreApplication::applicationDirPath() + "/../build-helloworldplugin-Desktop_Qt_6_6_2_MinGW_64_bit-Debug/libhelloworldplugin.dll";

    // Load the plugin
    QPluginLoader loader(pluginPath);
    if (!loader.load()) {
        qDebug() << "Error loading plugin:" << loader.errorString();
        return 1;
    }

    // Access the plugin
    HelloPluginInterface *plugin = qobject_cast<HelloPluginInterface*>(loader.instance());
    if (!plugin) {
        qDebug() << "Error casting plugin instance";
        return 1;
    }

    // Use the plugin
    plugin->hello();

    return 0;
}
