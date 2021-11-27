//
// Created by bakashigure on 11/24/2021.
//

#ifndef KHAYON_ARKNIGHTS_OPERATORINFO_H
#define KHAYON_ARKNIGHTS_OPERATORINFO_H
#include "../utils/configor_0.9.14/json.hpp"

namespace kaltsit{
    struct operators    {
        std::string name; // 干员名称
        char level; // 干员星级
        std::vector<std::string> tag; //携带词条
    };
class OperatorInfo{
    OperatorInfo();
    ~OperatorInfo();

protected:
    bool load_operator_data(const std::string& path);

private:

};
}

#endif //KHAYON_ARKNIGHTS_OPERATORINFO_H
