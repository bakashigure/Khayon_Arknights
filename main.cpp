#include <QApplication>
#include <QPushButton>
#include "src/Khayon_Gui/khayon.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Khayon w;
    w.show();
    /*
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    */
     return QApplication::exec();
}
