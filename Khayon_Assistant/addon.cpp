#include <napi.h>
#include "Khayon.h"
#include <vector>

Napi::Array Method(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Array ar = Napi::Array::New(env,5);

    std::vector<int> sb = {1,2,3,4,5};
    for(int i=0;i<sb.size();i++)
    {
        ar.Set(i,sb[i]);
    }


    return ar;
    
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"),
                Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(hello, Init)