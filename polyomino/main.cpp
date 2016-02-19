#include <QApplication>
#include <QPushButton>
#include "window.h"

int main(int argc, char** argv){
    // Setup App
    QApplication app(argc, argv);

    Window window;


    window.show();
    return app.exec();
}
