//
// Created by bakashigure on 11/24/2021.
//

#ifndef KHAYON_ARKNIGHTS_OPERATOR_H
#define KHAYON_ARKNIGHTS_OPERATOR_H
#include "../utils/configor_0.9.14/json.hpp"

namespace kaltsit{
    struct op{
        std::string name; // 干员名称
        char level; // 干员星级
        std::vector<std::string> tag; //携带词条
    };
class Operator{
    Operator();

};
}

#endif //KHAYON_ARKNIGHTS_OPERATOR_H
