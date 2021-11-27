//
// Created by bakashigure on 11/27/2021.
//
#pragma once
#ifndef KHAYON_ARKNIGHTS_DEBUG_HPP
#define KHAYON_ARKNIGHTS_DEBUG_HPP
#include <vector>
#include "ui_Khayon.h"
#include <typeinfo>
QT_BEGIN_NAMESPACE
namespace Ui{class Debug;}
QT_END_NAMESPACE

namespace DBG{
class Debug{
public:
    Debug(Ui::Khayon *_ui){
        ui = _ui;
    };

    template<typename T>
    void operator() (T const& t)
    {
        ui->debug_output->clear();
        ui->debug_output->setText(t);
    }

    template<typename T>
    void operator() (std::vector<T> const& _vector) {
        ui->debug_output->clear();
        for (auto& item: _vector)
            ui->debug_output->append(QString::fromStdString(std::to_string(item)));
    }

    void operator()(std::vector<std::string> const& _vector){
        ui->debug_output->clear();
        for(const auto& item: _vector)
            ui->debug_output->append(QString::fromStdString(item));
    }

    template<typename T1, typename T2>
    void operator() (const std::map<T1,T2>& _map)
    {
        ui->debug_output->clear();
        for(const auto& kv:_map)
            ui->debug_output->append(cv(kv.first)+QString(":  ")+cv(kv.second));
    }

    template<typename T1, typename T2>
    void operator() (const std::unordered_map<T1,T2>& _map)
    {
        ui->debug_output->clear();
        for(const auto& kv:_map)
            ui->debug_output->append(cv(kv.first)+QString(": ")+cv(kv.second));
    }

    QString cv(int _num)
    {return QString::number(_num);}

    QString cv(std::string _s)
    {return QString::fromStdString(_s);}
private:
    Ui::Khayon *ui;
};
}
#endif //KHAYON_ARKNIGHTS_DEBUG_HPP
