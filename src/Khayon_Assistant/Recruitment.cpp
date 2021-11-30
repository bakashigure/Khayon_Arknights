//
// Created by bakashigure on 11/24/2021.
//

#include "Recruitment.h"
#include <functional>

void kaltsit::Recruitment::getTagOffset(const std::set<std::string>& recruit_tags_nameset) {
    int _offset = 1;
    for (const auto& _tag: recruit_tags_nameset) {
        tag_offset[_tag] = std::to_string(_offset);
        tag_offset[std::to_string(_offset)]=_tag;
        _offset++;
    }
}

void kaltsit::Recruitment::calcTag(std::set<std::string>& chosen_tag) {
    std::vector<int> chosen_tag_offset;
    chosen_tag_offset.reserve(chosen_tag.size());
    for (const auto& tag: chosen_tag)
        chosen_tag_offset.push_back(atoi(tag_offset[tag].c_str()));
    for (int i = 1; i < chosen_tag.size(); ++i) {
        //从小到大生成, 可以保证N个元素里任意N-1个肯定是经过计算排列过的,
        //所以只需要任选一个与剩下元素的结果取交集，即为N个元素的结果
        auto cnk_result = calcCNK(i, chosen_tag_offset);
        for(auto &_vector:cnk_result)
        {
            int offset = 0;
            for(auto &_value:_vector)
            {
                offset |= 1<< _value;
            }
            if(chosen_tag_res.find(offset)==chosen_tag_res.end()) continue;
            else
            {

            }
        }

    }


}

int kaltsit::Recruitment::countCNK(int n, int k) {
    // 计算Cnk Cnk = n! / (k!*(n-k)!)
    auto factorial = [](int n) {
        int _value = n;
        while (n-- > 1) _value *= n;
        return _value;
    };
    return factorial(n) / (factorial(k) * factorial(n - k));
}

std::set<std::vector<int>> kaltsit::Recruitment::calcCNK(int k, std::vector<int>& index) {
    std::set<std::vector<int>> res; //CNK的结果
    std::vector<int> elements; //相当于visit数组, 用于标记每次循环取哪些元素
    elements.resize(index.size());
    for (int i = 0; i < k; ++i) elements[i] = 1;
    do {
        std::vector<int> current_combination; //存放本次循环中的排列结果
        for (int i = 0; i < elements.size(); ++i)
            if (elements[i]) current_combination.push_back(index[i]);
        res.emplace(current_combination);
    } while (std::prev_permutation(elements.begin(), elements.end())); //循环取得所有排列
    return res;
}
