//
// Created by bakashigure on 12/1/2021.
//

#ifndef KHAYON_ARKNIGHTS_UTIL_H
#define KHAYON_ARKNIGHTS_UTIL_H

#include <ctime>
#include <iostream>
#define TIME_START clock_t start_time,end_time; start_time=clock();
#define TIME_END(target) end_time = clock(); std::cout<<(target)<<": "<< end_time-start_time<<"\n";


#endif //KHAYON_ARKNIGHTS_UTIL_H
