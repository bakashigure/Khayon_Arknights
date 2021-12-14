//
// Created by bakashigure on 11/24/2021.
//

#define FMT_HEADER_ONLY
#include "util.h"
#include "OperatorInfo.h"
#include "include/fmt_8.0.1/ranges.h"
#include "include/fmt_8.0.1/core.h"

#include <string>
#include <regex>

void kaltsit::OperatorInfo::loadTagsEnToZh(std::string&& tags_en_to_zh){
    std::ifstream tags(tags_en_to_zh);
    configor::json tags_json;
    tags >> tags_json;
    for(auto info = tags_json.begin();info!=tags_json.end();++info)
    {   
        this->tags_eng_to_zh[info.key()] = UtfToGbk(info.value().as_string());   
    }

    _debug("tags_en_to_zh")
    for(const auto& it:this->tags_eng_to_zh)
    std::cout<<fmt::format("{} {}",it.first,it.second);
}

auto sb(int a) -> a{

}

void kaltsit::OperatorInfo::loadRecruitOperators(std::string &&gacha_table)
{
    TIME_START
    std::ifstream recruit_ops_stream(gacha_table);
    configor::json recruit_ops_json;
    recruit_ops_stream >> recruit_ops_json;
    std::string raw_string = fmt::format(recruit_ops_json["recruitDetail"].as_string() + " "); //提取原始字符串,加个空格更好匹配
    auto _begin = raw_string.cbegin();
    auto _end = raw_string.cend();
    std::smatch result; // ↓小心正则 这个正则可以把所有可公招的干员名提取出来.
    std::regex pattern(
        "((?:/ |<@rc.eml>|\\n)([\u4E00-\u9FA5A-Za-z0-9]{2,}[-]{0,1}[A-Z,0-9]{1,}|[\u4e00-\u9fa5^]{1,})(?: |</>|\\n)|([\u4e00-\u9fa5^]{1,}$))");
    while (regex_search(_begin, _end, result, pattern, std::regex_constants::match_not_eol))
    {
        set_op_name.emplace(UtfToGbk(result.str(2)));//result.str(2)->干员名称  往nameset中塞干员名
        um_op_info.emplace(std::pair<std::string, Operator>{UtfToGbk(result.str(2)), Operator()}); //初始化公招干员信息
        _begin = result[0].second;
    }
    TIME_END("load ops")
}

void kaltsit::OperatorInfo::loadRecruitOperatorsDetail(std::string &&character_table)
{
    TIME_START
    std::ifstream operator_info_raw(character_table);
    configor::json operator_info_json;
    auto &tag = tags_eng_to_zh;
    operator_info_raw >> operator_info_json;
    for (const auto &info : operator_info_json)
    {
        //std::cout<<fmt::format("name:{}\n",UtfToGbk(info["name"].as_string().c_str()));
        std::string _name = UtfToGbk(info["name"].as_string());
        if (um_op_info.find(_name) != um_op_info.end())
        {
            auto &op = um_op_info[_name];
            op.name = _name;
            op.level = info["rarity"].as_integer() + 1;
            if (op.level < 3 || op.level > 4)
                op.tag.emplace(tag[fmt::format("star{}", op.level)]);
            op.desp = UtfToGbk(info["itemDesc"].as_string());
            op.tag.emplace(tag[info["position"].as_string()]);
            op.tag.emplace(tag[UtfToGbk(info["profession"].as_string())]);
            for (const auto &_tag : info["tagList"])
                op.tag.emplace(UtfToGbk(_tag));
            for (const auto &_tag : op.tag) // 塞入tag:干员 表
                um_tag_ops[_tag].emplace(op.name);

            //std::cout<<fmt::format("op.name:{} op.level:{} op.itemDesc:{} op.tags{}\n",op.name,op.level,op.desp,op.tag);
        }
    }
    for (const auto &kv : um_tag_ops)
        set_tags.emplace(kv.first);
    TIME_END("load ops detail")
    std::cout<<fmt::format("{}\n",this->set_op_name);
};

int kaltsit::OperatorInfo::getStar(std::string op_name){
    return um_op_info[op_name].level;
};
