#pragma once
#ifndef NAPI
    #define NAPI
    #include <napi.h>
#endif
#include "include/moonshine-cpp.h"
#include "mic.h"
class Processer : public moonshine::TranscriptEventListener{
public:
    Napi::FunctionReference* Callback;
    Processer();
    void onLineCompleted(const moonshine::LineCompleted &event) override;
    void onLineStarted(const moonshine::LineStarted &event) override;
    void onLineUpdated(const moonshine::LineUpdated &event) override;
    void onLineTextChanged(const moonshine::LineTextChanged &event) override;
    void LoadMutationFile(const std::string file_name);
};