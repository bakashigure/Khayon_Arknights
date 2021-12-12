//
// Created by bakashigure on 12/1/2021.
//

#ifndef KHAYON_ARKNIGHTS_UTIL_H
#define KHAYON_ARKNIGHTS_UTIL_H

#include <chrono>
#include <iostream>
#include "include/fmt_8.0.1/core.h"
#define TIME_START          auto __start = std::chrono::steady_clock::now();
#define TIME_END(target)    auto __end = std::chrono::steady_clock::now();                      \
                            std::chrono::duration<double,std::milli> elapsed = __end - __start; \
                            std::cout<<fmt::format("{}: {}ms\n",(target),elapsed.count());


#endif //KHAYON_ARKNIGHTS_UTIL_H
