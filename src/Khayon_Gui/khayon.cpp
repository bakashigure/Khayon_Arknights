//
// Created by bakashigure on 11/24/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Khayon.h" resolved

#include "khayon.h"


Khayon::Khayon(QWidget *parent) : QWidget(parent), ui(new Ui::Khayon) {
    ui->setupUi(this);
    opi=nullptr;
}

void Khayon::init() {
    auto *op= new kaltsit::OperatorInfo();
    opi = op;
    opi->loadOperators("../src/resources/character_table.json");
}

Ui::Khayon *Khayon::get_ui() const {
    return ui;
}

Khayon::~Khayon() {
    delete ui;
}

