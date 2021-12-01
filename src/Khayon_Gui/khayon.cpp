//
// Created by bakashigure on 11/24/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Khayon.h" resolved

#include "khayon.h"
#include <utility>


Khayon::Khayon(QWidget *parent) : QWidget(parent), ui(new Ui::Khayon) {
    ui->setupUi(this);
}

void Khayon::init() {
    opi = new kaltsit::OperatorInfo();
    opi->loadRecruitOperators("../src/resources/gacha_table.json");
    opi->loadRecruitOperatorsDetail("../src/resources/character_table.json");
    recruit= new kaltsit::Recruitment(opi->um_tag_ops);
    std::set<std::string> a = {"近战位"};
    std::set<std::string> b = {"近战位", "狙击干员"};
    std::set<std::string> c = {"近战位", "狙击干员", "减速"};
    std::set<std::string> d = {"近战位", "狙击干员", "减速", "削弱"};

    recruit->calcTag(a);
    recruit->calcTag(b);

    recruit->calcTag(c);

    recruit->calcTag(d);

}

Ui::Khayon *Khayon::get_ui() const {
    return ui;
}

Khayon::~Khayon() {
    delete ui;
    delete opi;
}

