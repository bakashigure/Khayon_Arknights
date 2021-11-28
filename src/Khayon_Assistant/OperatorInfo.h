//
// Created by bakashigure on 11/24/2021.
//

#ifndef KHAYON_ARKNIGHTS_OPERATORINFO_H
#define KHAYON_ARKNIGHTS_OPERATORINFO_H
#include "../utils/configor_0.9.14/json.hpp"
#include "debug.hpp"
#include <fstream>

namespace kaltsit{
    struct Operator{
        std::string name; // 干员名称
        unsigned short level; // 干员星级
        std::set<std::string> tag; //携带词条
        std::string comment; //简要说明
    };

    class OperatorInfo{
    public:
        OperatorInfo()= default;;
        //~OperatorInfo();
        void loadOperators(std::string &&character_table);

    protected:
        bool load_operator_data(const std::string& path);

    private:
        std::unordered_map<std::string,Operator> op; //干员详细信息 k:干员名称, v:干员信息
        std::unordered_map<std::string,std::string> sb;
    };
}

#endif //KHAYON_ARKNIGHTS_OPERATORINFO_H
