//
// Created by bakashigure on 11/24/2021.
//
#pragma once
#ifndef KHAYON_ARKNIGHTS_KHAYON_H
#define KHAYON_ARKNIGHTS_KHAYON_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Khayon; }
QT_END_NAMESPACE

class Khayon : public QWidget{
Q_OBJECT

public:
    explicit Khayon(QWidget *parent = nullptr);

    ~Khayon() override;

private:
    Ui::Khayon *ui;
};


#endif //KHAYON_ARKNIGHTS_KHAYON_H
