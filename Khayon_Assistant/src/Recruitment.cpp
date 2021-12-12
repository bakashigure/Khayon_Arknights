//
// Created by bakashigure on 11/24/2021.
//

#include "Recruitment.h"
#include <functional>

kaltsit::Recruitment::Recruitment(std::unordered_map<std::string, std::set<std::string>>& _um_tag_ops) {
    TIME_START
    this->um_tag_ops = &_um_tag_ops;
    getTagOffset(*um_tag_ops);
    for (const auto& kv: _um_tag_ops)
        chosen_tag_res[atoi(tag_offset[kv.first].c_str())] = kv.second; //预先计算所有单tag的招募结果
    TIME_END("load Recruitment constructor")
}


void kaltsit::Recruitment::getTagOffset(const std::set<std::string>& _recruit_tags_nameset) {
    tag_offset.clear();
    int _offset = 1;
    for (const auto& _tag: _recruit_tags_nameset) {
        tag_offset[_tag] = std::to_string(1 << _offset);
        tag_offset[std::to_string(1 << _offset)] = _tag;
        _offset++;
    }
}

void kaltsit::Recruitment::getTagOffset(std::unordered_map<std::string, std::set<std::string>>& um_ops_nameset) {
    tag_offset.clear();
    int _offset = 1;
    for (const auto& kv: um_ops_nameset) {
        tag_offset[kv.first] = std::to_string(1 << _offset);
        tag_offset[std::to_string(1 << _offset)] = kv.first;
        _offset++;
    }
}


std::unordered_map<int, std::set<std::string>> kaltsit::Recruitment::calcTag(std::set<std::string>& chosen_tag) {
    TIME_START
    auto& ctr = chosen_tag_res;
    std::vector<int> chosen_tag_offset;
    std::unordered_map<int, std::set<std::string>> current_res;
    chosen_tag_offset.reserve(chosen_tag.size());
    for (const auto& tag: chosen_tag)
        chosen_tag_offset.push_back(atoi(tag_offset[tag].c_str()));
    for (int i = 1; i <= chosen_tag.size(); ++i) {
        //从小到大生成, 可以保证N个元素里任意N-1个肯定是经过计算排列过的,
        //所以只需要把N个元素的offset和任意N-1个元素的offset异或一下，即为多出来的元素,
        //将多出来的元素和N-1取交集, 就是N个元素的结果.
        auto cnk_result = calcCNK(i, chosen_tag_offset);
        for (auto& _vector: cnk_result) {
            int _offset = 0;
            for (auto& _value: _vector) _offset |= _value;
            if (current_res.find(_offset) != current_res.end()) continue;
            else {
                if (i == 1) current_res[_offset] = chosen_tag_res[_offset];
                else
                    for (const auto& kv: current_res)
                        if (countOffsets(i - 1, kv.first)) {
                            // std::cout<<"enter count_offsets: "<<i<<"\n";
                            std::vector<std::string> v1, v2; // 好想用cpp20的set_intersection啊...
                            v1.assign(kv.second.begin(), kv.second.end());
                            v2.assign(chosen_tag_res[kv.first^_offset].begin(), chosen_tag_res[kv.first^_offset].end());
                            std::vector<std::string> v3;
                            std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
                                                  std::inserter(v3, v3.begin()));
                            chosen_tag_res[_offset] = std::set<std::string>(v3.begin(), v3.end());
                            if (!chosen_tag_res[_offset].empty())
                                current_res[_offset] = chosen_tag_res[_offset];
                        }
            }
        }
    }
    return current_res;

    /*
    for (auto kv: current_res)
        std::cout << fmt::format("{}: {}", kv.first, kv.second) << "\n";
    */
     //std::cout << fmt::format("start_time:{}   end_time:{}\n", start_time, end_time);
    TIME_END("load calc_tag")
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

bool kaltsit::Recruitment::countOffsets(int n, int offset) {
    int cnt = 0;
    while (offset) {
        if (offset&1) cnt++;
        offset >>= 1;
    }
    return cnt == n;
}

