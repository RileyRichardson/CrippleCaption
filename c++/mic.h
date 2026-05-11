#pragma once
#include <iostream>
#include "include/miniaudio.h"
#include "include/moonshine-cpp.h"
#include "process.h"
void data_callback(ma_device* device, void* output, const void* input,ma_uint32 frameCount);
class MicTranscriber{
    moonshine::Transcriber transcriber;
    ma_device_config config;
    ma_device device;
    bool running;
    bool init = false;
public:
    MicTranscriber(moonshine::TranscriptEventListener* p);
    ~MicTranscriber();
    void Start();
    void Stop();
};