#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "FilterableImage.h"

void registerQmlTypes()
{
    qmlRegisterType<FilterableImage>("on.someedit", 1, 0, "FilterableImage");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    registerQmlTypes();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
