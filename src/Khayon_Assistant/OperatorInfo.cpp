//
// Created by bakashigure on 11/24/2021.
//

#include "OperatorInfo.h"
#include "../utils/fmt_8.0.1/core.h"
#include <string>

void kaltsit::OperatorInfo::loadOperators(std::string &&character_table) {
  std::ifstream operator_info_raw(character_table);
  configor::json operator_info_json;
  operator_info_raw >> operator_info_json;
  auto it = operator_info_json.begin();
  Debug d;


  std::string s = fmt::format("The answer is {}.", 42);


  std::string ss = fmt::format("get {0}", it.value()["itemObtainApproach"].dump());
  QString obtainA =  d.cv(fmt::format("get{}", it.value()["itemObtainApproach"].dump()));
};

