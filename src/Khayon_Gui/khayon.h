//
// Created by bakashigure on 11/24/2021.
//
#pragma once
#ifndef KHAYON_ARKNIGHTS_KHAYON_H
#define KHAYON_ARKNIGHTS_KHAYON_H

#include <QWidget>
#include "ui_Khayon.h"
#include "../Khayon_Assistant/OperatorInfo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Khayon;}
QT_END_NAMESPACE

class Khayon : public QWidget{
Q_OBJECT

public:
    explicit Khayon(QWidget *parent = nullptr);
    ~Khayon() override;
    void  init();
    Ui::Khayon* get_ui() const;

private:
    Ui::Khayon *ui;
    kaltsit::OperatorInfo *opi;
};


#endif //KHAYON_ARKNIGHTS_KHAYON_H
