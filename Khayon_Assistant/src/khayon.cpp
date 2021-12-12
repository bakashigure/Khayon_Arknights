//
// Created by bakashigure on 11/24/2021.
//

#include "Khayon.h"
#include <utility>

#define GET_ENV Napi::Env env = info.Env();
#define LOG(_CONTENT) _cb->Call({Napi::String::New(env,"log"),Napi::String::New(env,(_CONTENT))});


Napi::Object Khayon::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function func =
        DefineClass(env,
                    "Khayon",
                    {InstanceMethod("calcTag", &Khayon::calcTag),
                     InstanceMethod("getOps", &Khayon::getOps),
                     InstanceMethod("init", &Khayon::init)});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);

    exports.Set("Khayon", func);
    return exports;
}

Khayon::Khayon(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<Khayon>(info){

    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsFunction())
    {
        Napi::TypeError::New(env, "Log emitter expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::Function cb = info[0].As<Napi::Function>();
    _cb = new Napi::FunctionReference(Napi::Persistent(cb));

    _cb->Call({Napi::String::New(env,"log"),Napi::String::New(env,("Cons"))});
}


void Khayon::init(const Napi::CallbackInfo &info)
{
    GET_ENV
    LOG("go to init")
    opi = new kaltsit::OperatorInfo();
    LOG("1")
    opi->loadRecruitOperators("../Khayon_Assistant/src/resources/gacha_table.json");
    LOG("2")
    opi->loadRecruitOperatorsDetail("../Khayon_Assistant/src/resources/character_table.json");
    LOG("3")
    recruit = new kaltsit::Recruitment(opi->um_tag_ops);
    LOG("4")
    /*
    std::set<std::string> a = {"近战位"};
    std::set<std::string> b = {"近战位", "狙击干员"};
    std::set<std::string> c = {"近战位", "狙击干员", "减速"};
    std::set<std::string> d = {"近战位", "狙击干员", "减速", "削弱"};

    recruit->calcTag(a);
    recruit->calcTag(b);

    recruit->calcTag(c);

    recruit->calcTag(d);
    */
   LOG("init success")
}


Napi::Value Khayon::calcTag(const Napi::CallbackInfo &info)
{
    //Napi::Value -> Napi::Array
    GET_ENV
    std::set<std::string> args;
    for (int i = 0; i < info.Length(); ++i)
    {
        args.emplace(info[i].As<Napi::String>());
    }
    recruit->calcTag(args);

    Napi::Array ar = Napi::Array::New(env, 5);
    std::vector<int> sb = {1, 2, 3, 4, 5};

    ar.Set(uint32_t(0), 114);
    ar.Set(1, 514);

    return ar;
}

Napi::Value Khayon::getOps(const Napi::CallbackInfo &info)
{
    GET_ENV
    return Napi::Number::New(env, 0);
}
