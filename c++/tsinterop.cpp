#include "process.h"
#include "mic.h"
#include <napi.h>
#include <fstream>

MicTranscriber* transcriber=nullptr;
Processer* proceser=nullptr;

Napi::Value SetCallBack(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    if (!info[0].IsFunction()) {
        Napi::TypeError::New(env, "Function expected").ThrowAsJavaScriptException();
        return env.Null();
    }
    proceser->SetCallBack(Napi::ThreadSafeFunction::New(env,info[0].As<Napi::Function>(),"tsCall",0,1));
    return env.Undefined();
}
Napi::Value unInit(const Napi::CallbackInfo& info){
    if(transcriber)delete transcriber;
    if(proceser)delete proceser;
    return info.Env().Undefined();
}
Napi::Value LoadMutationFile(const Napi::CallbackInfo& info){
    std::string Lang = info[0].As<Napi::String>();

    return info.Env().Undefined();
}
Napi::Value StartTranscribing(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    transcriber->Start();
    return env.Undefined();
}
Napi::Value StopTranscribing(const Napi::CallbackInfo& info){
   transcriber->Stop();
   return info.Env().Undefined();
}
Napi::Value Init(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    if(!info[0].IsString()){
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
        return env.Null();
    }
    proceser = new Processer();
    transcriber = new MicTranscriber(proceser,info[0].As<Napi::String>());
    return env.Undefined();
}
Napi::Object ExportFuncs(Napi::Env env, Napi::Object exports){
    exports.Set(Napi::String::New(env,"Init"),Napi::Function::New(env,Init));
    exports.Set(Napi::String::New(env,"SetCallBack"),Napi::Function::New(env,SetCallBack));
    exports.Set(Napi::String::New(env,"LoadMutationFile"),Napi::Function::New(env,LoadMutationFile));
    exports.Set(Napi::String::New(env,"unInit"),Napi::Function::New(env,unInit));
    exports.Set(Napi::String::New(env,"StartTranscribing"),Napi::Function::New(env,StartTranscribing));
    exports.Set(Napi::String::New(env,"StopTranscribing"),Napi::Function::New(env,StopTranscribing));
    return exports;
}
NODE_API_MODULE(tsinterop, ExportFuncs);