//
// Created by bakashigure on 11/24/2021.
//

#ifndef KHAYON_ARKNIGHTS_RECRUITMENT_H
#define KHAYON_ARKNIGHTS_RECRUITMENT_H

#include "util.h"
#include <unordered_map>
#include <vector>
#include <set>
#include "include/fmt_8.0.1/ranges.h"
#include "include/fmt_8.0.1/core.h"
#include <unordered_set>

namespace kaltsit {
    class Recruitment{
    public:
        explicit Recruitment(std::unordered_map<std::string,std::set<std::string>> &_um_tag_ops);
        ~Recruitment() = default;

        void getTagOffset(const std::set<std::string>& recruit_tags_nameset);
        void getTagOffset(std::unordered_map<std::string,std::set<std::string>>& um_ops_nameset);
        void calcTag(std::set<std::string>& chosen_tag);

    private:
        std::set<std::string> recruit_tags_nameset; //公招所有tag

        std::unordered_map<std::string, std::string> tag_offset; // k:tag v:offset
        std::unordered_map<int,std::set<std::string>> chosen_tag_res; //选中tag的聚合结果, 全局保存给下次使用
        std::unordered_map<std::string,std::set<std::string>> *um_tag_ops; //从OperatorInfo搞一个来

        static int countCNK(int n,int k); //计算排列组合共有多少个
        static bool countOffsets(int n,int offset);
        std::set<std::vector<int>> calcCNK(int k,std::vector<int>& index);
    };

}


#endif //KHAYON_ARKNIGHTS_RECRUITMENT_H
