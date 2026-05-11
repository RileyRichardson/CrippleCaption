#ifndef NAPI
    #define NAPI
    #include <napi.h>
#endif
#include "process.h"
#include "mic.h"


MicTranscriber* transcriber=nullptr;
Processer* proceser=nullptr;
Napi::FunctionReference* callback=nullptr;

Napi::Value SetCallBack(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    if (!info[0].IsFunction()) {
        Napi::TypeError::New(env, "Function expected").ThrowAsJavaScriptException();
        return env.Null();
    }
    if(callback)delete callback;
    callback = new Napi::FunctionReference(Napi::Persistent(info[0].As<Napi::Function>()));
    proceser->Callback=callback;
    return env.Undefined();
}
Napi::Value unInit(const Napi::CallbackInfo& info){
    if(transcriber)delete transcriber;
    if(proceser)delete proceser;
    if(callback)delete callback;
    return info.Env().Undefined();
}
Napi::Value LoadMutationFile(const Napi::CallbackInfo& info){
    std::string Lang = info[0].As<Napi::String>();

    return info.Env().Undefined();
}
Napi::Value StartTranscribing(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    if(!callback){
        Napi::TypeError::New(env,"No Callback Provided").ThrowAsJavaScriptException();
        return env.Undefined();
    }
    transcriber->Start();
    return env.Undefined();
}
Napi::Value StopTranscribing(const Napi::CallbackInfo& info){
   transcriber->Stop();
   return info.Env().Undefined();
}
Napi::Object Init(Napi::Env env, Napi::Object exports){
    proceser = new Processer();
    transcriber = new MicTranscriber(proceser);
    exports.Set(Napi::String::New(env,"SetCallBack"),Napi::Function::New(env,SetCallBack));
    exports.Set(Napi::String::New(env,"LoadMutationFile"),Napi::Function::New(env,LoadMutationFile));
    exports.Set(Napi::String::New(env,"unInit"),Napi::Function::New(env,unInit));
    exports.Set(Napi::String::New(env,"StartTranscribing"),Napi::Function::New(env,StartTranscribing));
    exports.Set(Napi::String::New(env,"StopTranscribing"),Napi::Function::New(env,StopTranscribing));
    return exports;
}
NODE_API_MODULE(cppInterop, Init);