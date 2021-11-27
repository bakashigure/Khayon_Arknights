#include <QApplication>
#include <QPushButton>
#include "src/Khayon_Gui/khayon.h"
#include <vector>
#include "src/Khayon_Assistant/debug.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Khayon w;

    w.show();
    Debug dbg(w.get_ui());
    std::vector<std::string> sb={"1","2","3","4"};
    std::map<int,int> sbb={std::pair<int,int>{1,2},std::pair<int,int>{3,50}};
    std::vector<int> ssb={1,2,3,4,5};
    std::string s("114514");

    dbg(sbb);

    return QApplication::exec();
}
