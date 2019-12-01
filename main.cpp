#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Controller controller;

    controller.start(500);

    return app.exec();
}
