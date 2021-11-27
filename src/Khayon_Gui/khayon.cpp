//
// Created by bakashigure on 11/24/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Khayon.h" resolved

#include "khayon.h"


Khayon::Khayon(QWidget *parent) : QWidget(parent), ui(new Ui::Khayon) {
    ui->setupUi(this);
}

Khayon::~Khayon() {
    delete ui;
}

