//
// Created by bakashigure on 11/24/2021.
//

#ifndef KHAYON_ARKNIGHTS_RECRUITMENT_H
#define KHAYON_ARKNIGHTS_RECRUITMENT_H

#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_set>

namespace kaltsit {
    class Recruitment{
    public:
        Recruitment() = default;
        ~Recruitment() = default;

        void getTagOffset(const std::set<std::string>& recruit_tags_nameset);
        void calcTag(std::set<std::string>& chosen_tag);

    private:
        std::unordered_map<std::string, std::string> tag_offset; // k:tag v:offset
        std::unordered_map<int,std::set<std::string>> chosen_tag_res; //选中tag的聚合结果
        static int countCNK(int n,int k); //计算排列组合共有多少个
        std::set<std::vector<int>> calcCNK(int k,std::vector<int>& index);
    };

}


#endif //KHAYON_ARKNIGHTS_RECRUITMENT_H
