//
// Created by bakashigure on 11/24/2021.
//

#include "Khayon.h"
#include <utility>
#include <iostream>
#include <string>
#include "util.h"
#include "node.h"
#define LOG(_CONTENT) _cb->Call({Napi::String::New(env,"log"),Napi::String::New(env,(_CONTENT))});


Napi::Object Khayon::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Khayon", {InstanceMethod("calcTag", &Khayon::calcTag),
                                                       InstanceMethod("getOps",&Khayon::getOps),
                                                      InstanceMethod("init", &Khayon::init)});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);

    exports.Set("Khayon", func);
    return exports;
}

Khayon::Khayon(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Khayon>(info) {

    GET_ENV
    if (info.Length() < 1 || !info[0].IsFunction()) {
        Napi::TypeError::New(env, "Log emitter expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::Function cb = info[0].As<Napi::Function>();
    _cb = new Napi::FunctionReference(Napi::Persistent(cb));

    _cb->Call({Napi::String::New(env, "log"), Napi::String::New(env, ("Cons"))});
}


void Khayon::init(const Napi::CallbackInfo& info) {
    GET_ENV

    LOG("go to init")
    opi = new kaltsit::OperatorInfo();
    opi->loadTagsEnToZh("E:/Code/c++/Khayon_Arknights/Khayon_Assistant/src/resources/tags_en_to_zh.json");
    opi->loadRecruitOperators("E:/Code/c++/Khayon_Arknights/Khayon_Assistant/src/resources/gacha_table.json");
    opi->loadRecruitOperatorsDetail("E:/Code/c++/Khayon_Arknights/Khayon_Assistant/src/resources/character_table.json");
    recruit = new kaltsit::Recruitment(opi->um_tag_ops);

    LOG("init success")
}



Napi::Value Khayon::calcTag(const Napi::CallbackInfo& info) {
    //Napi::Value -> Napi::Array
    GET_ENV
    if (info.Length() < 1 || info.Length() > 5)
    {
        Napi::TypeError::New(env, "Invalid args in calcTag").ThrowAsJavaScriptException();
        return Napi::String::New(env,"Invalid args in calcTag");
    }

    std::set<std::string> args;
    for (int i = 0; i < info.Length(); ++i) {
        args.emplace(UtfToGbk(std::string(info[i].As<Napi::String>().Utf8Value()).c_str()));

    }

    
    std::cout<<fmt::format("args: {} \n",args);
    auto res = recruit->calcTag(args);


    for(auto& it:res)
    {
        auto name_set = recruit->offsetToName(it.first);
        std::cout<<fmt::format("name_set: {}\n",name_set);
        std::cout<<fmt::format("ops: {}\n",it.second);
    }

    auto union_tag = [&](std::set<std::string> st){
        Napi::Array name_level = Napi::Array::New(env);
        for(auto& it:st)
        {
            name_level.Set(Napi::String::New(env,GbkToUtf(it)),opi->getStar(it));
        }
        return name_level;
    };

   
    std::cout<<"\n_________res_________:\n";
    for(auto& it:res)
    {
        std::cout<<fmt::format("k:{} v:{}\n",it.first,it.second);
    }
   

   
    Napi::Array ar = Napi::Array::New(env,res.size());
    for(auto& it:res)
    {
        ar.Set(std::to_string(it.first),union_tag(it.second));
    }

    return ar;
}

Napi::Value Khayon::getOps(const Napi::CallbackInfo& info) {
    GET_ENV
    
    return Napi::String::New(env,"测试");
}
