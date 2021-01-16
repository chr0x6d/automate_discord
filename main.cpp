#include <QtWidgets>
#include "mainwindow.h"
#include "style.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.resize(400, 300);
    w.show();

    a.setStyle(new MyProxyStyle(a.style()));
    return a.exec();
}
