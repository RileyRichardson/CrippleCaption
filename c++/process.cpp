#pragma once
#include "process.h"

Processer::Processer():Callback(nullptr){

}
void Processer::onLineCompleted(const moonshine::LineCompleted &event){
    if(!Callback)return;
    Callback->Call({Napi::String::New(Callback->Env(),event.line.text)});
}
void Processer::onLineStarted(const moonshine::LineStarted &event){
    
}
void Processer::onLineUpdated(const moonshine::LineUpdated &event){
    
}
void Processer::onLineTextChanged(const moonshine::LineTextChanged &event){
    
}
void Processer::LoadMutationFile(const std::string file_name){

}