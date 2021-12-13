#include <napi.h>
#include "src/Khayon.h"
#include <vector>

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Khayon::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)