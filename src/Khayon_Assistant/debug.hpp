//
// Created by bakashigure on 11/27/2021.
//
#pragma once
#ifndef KHAYON_ARKNIGHTS_DEBUG_HPP
#define KHAYON_ARKNIGHTS_DEBUG_HPP
#include <vector>
#include "ui_Khayon.h"
#include <typeinfo>
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui{class Debug;}
QT_END_NAMESPACE

class Debug{
public:
    Debug()= default;
    explicit Debug(Ui::Khayon *_ui){
        ui = _ui;
    };
    ~Debug() = default;



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

    template<typename T>
    void operator() (const std::set<T>& _set) const
    {
        ui->debug_output->clear();
        for(const auto& v:_set)
            ui->debug_output->append(cv(v));
    }

    template<typename T>
    void operator() (std::set<T>& _set) const
    {
        ui->debug_output->clear();
        for(const auto& v:_set)
            ui->debug_output->append(cv(v));
    }

    void operator() (std::set<std::string>&& _set)
    {
        ui->debug_output->clear();
        for(const auto& v:_set)
            ui->debug_output->append(cv(v));
    }

    void operator() (QString _qs){
        ui->debug_output->clear();
        ui->debug_output->append(_qs);
    }
    QString cv(int &_num) const
    {return QString::number(_num);}

    QString cv(int const& _num) const{
        return QString::number(_num);
    }

    QString cv(std::string &_string) const
    {return QString::fromStdString(_string);}

    QString cv(std::string const& _string) const{
        return QString::fromStdString(_string);
    }


    static Ui::Khayon* ui;

    static void set_ui(Ui::Khayon* _ui)
    {
        ui=_ui;
    }
};



#endif //KHAYON_ARKNIGHTS_DEBUG_HPP
