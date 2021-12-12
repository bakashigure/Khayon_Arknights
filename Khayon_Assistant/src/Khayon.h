//
// Created by bakashigure on 12/9/2021.
//

#ifndef KHAYON_ASSISTANT_KHAYON_H
#define KHAYON_ASSISTANT_KHAYON_H

#define GET_ENV Napi::Env env = info.Env();

#include <napi.h>
#include "Recruitment.h"
#include "OperatorInfo.h"
#include <unordered_map>
#include <set>
#include <map>
#include <string>

class Khayon : public Napi::ObjectWrap<Khayon>
{
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Khayon(const Napi::CallbackInfo &info);

    void init(const Napi::CallbackInfo &info);
    Napi::Value getOps(const Napi::CallbackInfo &info);  // Napi::Value -> Napi::Array
    Napi::Value calcTag(const Napi::CallbackInfo &info); //


private:
    kaltsit::OperatorInfo *opi;
    kaltsit::Recruitment *recruit;

    Napi::FunctionReference *_cb;


};

#endif //KHAYON_ASSISTANT_KHAYON_H
