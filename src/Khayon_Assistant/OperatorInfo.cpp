//
// Created by bakashigure on 11/24/2021.
//
#define FMT_HEADER_ONLY

#include "OperatorInfo.h"
#include "../utils/fmt_8.0.1/ranges.h"
#include "../utils/fmt_8.0.1/core.h"

#include <string>
#include <regex>

std::unordered_map<std::string,std::string> kaltsit::OperatorInfo::tags_eng_to_zh= {
        {"RANGED", "远程位"},
        {"MEDIC", "医疗干员"},
        {"MELEE","近战位"},
        {"PIONEER","先锋干员"},
        {"SNIPER","狙击干员"},
        {"CASTER","术士干员"},
        {"WARRIOR","近卫干员"},
        {"TANK","重装干员"},
        {"SUPPORT","辅助干员"},
        {"SPECIAL","特种干员"},
        {"star5","资深干员"},
        {"star6","高级资深干员"}
};


void kaltsit::OperatorInfo::loadRecruitOperators(std::string&& gacha_table) {
    std::ifstream recruit_ops_stream(gacha_table);
    configor::json recruit_ops_json;
    recruit_ops_stream >> recruit_ops_json;
    std::string raw_string = fmt::format(recruit_ops_json["recruitDetail"].as_string()+" ");  //提取原始字符串,加个空格更好匹配
    auto _begin = raw_string.cbegin();
    auto _end = raw_string.cend();
    std::smatch result; // ↓小心正则
    std::regex pattern("((?:/ |<@rc.eml>|\\n)([\u4E00-\u9FA5A-Za-z0-9]{2,}[-]{0,1}[A-Z,0-9]{1,}|[\u4e00-\u9fa5^]{1,})(?: |</>|\\n)|([\u4e00-\u9fa5^]{1,}$))");
    while (regex_search(_begin, _end, result, pattern, std::regex_constants::match_not_eol))
    {
        recruit_ops_nameset.emplace(result.str(2)); //往nameset中塞干员名
        recruit_ops.emplace(std::pair<std::string,Operator>{result.str(2),Operator()}); //初始化公招干员信息
        _begin = result[0].second;
    }
    Debug d;d(recruit_ops_nameset);
}

void kaltsit::OperatorInfo::loadRecruitOperatorsDetail(std::string&& character_table) {
    std::ifstream operator_info_raw(character_table);
    configor::json operator_info_json;
    auto& tag = tags_eng_to_zh;
    operator_info_raw >> operator_info_json;
    for(const auto &info: operator_info_json)
    {
        if(recruit_ops.find(info["name"].as_string())!=recruit_ops.end())
        {
            auto &op = recruit_ops[info["name"].as_string()];
            op.name = info["name"].as_string();
            op.level = info["rarity"].as_integer()+1;
            if(op.level==5||op.level==6||op.level==2)
                op.tag.emplace(tag[fmt::format("star{}",op.level)]);
            op.desp = info["itemDesc"].as_string();
            op.tag.emplace(tag[info["position"].as_string()]);
            op.tag.emplace(tag[info["profession"].as_string()]);
            for(const auto& _tag:info["tagList"])
                op.tag.emplace(_tag);
        }
    }
    Debug d;

    auto _dd = fmt::format("name: {}\n tag: {}\n desc:{}",recruit_ops["红"].name,recruit_ops["红"].tag,recruit_ops["红"].desp);
    d(d.cv(_dd));

};

