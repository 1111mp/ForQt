#include <QApplication>
#include <QDir>

#include "src/application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    QApplication::setQuitOnLastWindowClosed(false);

    Application app;

    return a.exec();
}
