//
// Created by bakashigure on 12/9/2021.
//

#ifndef KHAYON_ASSISTANT_KHAYON_H
#define KHAYON_ASSISTANT_KHAYON_H

#define GET_ENV Napi::Env env = info.Env();


#include <napi.h>
#include "Recruitment.h"
#include "OperatorInfo.h"

class Khayon{
public:
    Khayon() = default;
    void init();
    kaltsit::OperatorInfo *opi;
    kaltsit::Recruitment *recruit;

    Napi::Array get_ops(const Napi::CallbackInfo& info);

};


#endif //KHAYON_ASSISTANT_KHAYON_H

