//
// Created by bakashigure on 11/24/2021.
//

#ifndef KHAYON_ARKNIGHTS_OPERATORINFO_H
#define KHAYON_ARKNIGHTS_OPERATORINFO_H
#include "include/configor_0.9.14/json.hpp"
#include <fstream>
#include <utility>

namespace kaltsit{
    struct Operator{
        Operator()= default;
        Operator(std::string name,unsigned short level,std::set<std::string> tag,std::string desp):
            name(std::move(name)),level(level),tag(std::move(tag)),desp(std::move(desp)){};
        ~Operator() = default;
        std::string name; // 干员名称
        unsigned short level; // 干员星级
        std::set<std::string> tag; //携带词条
        std::string desp; //简要说明
    };

    class OperatorInfo{
    public:
        OperatorInfo() = default;;
        ~OperatorInfo() = default;
        void loadRecruitOperators(std::string&& gacha_table);
        void loadRecruitOperatorsDetail(std::string&& character_table);

        std::unordered_map<std::string,std::set<std::string>> um_tag_ops;
    protected:
        std::set<std::string> set_tags; //公招所有tag
        //k:tag v:所有包含此tag的公招人员


    private:
        std::unordered_map<std::string,Operator> um_op_info; // unordered_map_operator_info 干员详细信息 k:干员名称, v:干员信息

        std::set<std::string> set_op_name; //公招所有干员名称
        static std::unordered_map<std::string,std::string> tags_eng_to_zh; // 英中的tag对照表
    };
}


#endif //KHAYON_ARKNIGHTS_OPERATORINFO_H
