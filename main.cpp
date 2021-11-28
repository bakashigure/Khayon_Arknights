#include <QApplication>
#include <QPushButton>
#include "src/Khayon_Gui/khayon.h"
#include <vector>
#include "src/Khayon_Assistant/debug.hpp"
#include "src/utils/fmt_8.0.1/core.h"

Ui::Khayon* Debug::ui = reinterpret_cast<Ui::Khayon *>(0);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Khayon w;
    w.show();
    Debug::set_ui(w.get_ui());
    w.init();
    Debug dbg;
    std::vector<std::string> sb={"1","2","3","4"};
    std::map<int,int> sbb={std::pair<int,int>{1,2},std::pair<int,int>{3,50}};
    std::vector<int> ssb={1,2,3,4,5};





    return QApplication::exec();
}
