#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///mapMarker.qml")));
    view.show();
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/map.qml")));

    return app.exec();
}
