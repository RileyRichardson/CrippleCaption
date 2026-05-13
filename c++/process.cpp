#pragma once
#include "process.h"
#include <fstream>

Processer::Processer():Callback(nullptr){

}
void Processer::onLineCompleted(const moonshine::LineCompleted &event){
    if(!Callback)return;
    auto callback = [text = event.line.text](Napi::Env env, Napi::Function jsCallback) {
        jsCallback.Call({Napi::String::New(env, text)});
    };
    Callback.BlockingCall(callback);
}
void Processer::onLineStarted(const moonshine::LineStarted &event){
    
}
void Processer::onLineUpdated(const moonshine::LineUpdated &event){
    
}
void Processer::onLineTextChanged(const moonshine::LineTextChanged &event){
    
}
void Processer::LoadMutationFile(const std::string file_name){

}
void Processer::SetCallBack(Napi::ThreadSafeFunction callback){
    Callback=callback;
}