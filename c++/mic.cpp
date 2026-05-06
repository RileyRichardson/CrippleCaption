#define MINIAUDIO_IMPLEMENTATION
#include "include/moonshine-cpp.h"
#include "include/miniaudio.h"
#include <iostream>
void data_callback(ma_device* device, void* output, const void* input,ma_uint32 frameCount) {
    ((moonshine::Transcriber*)(device->pUserData))->addAudio((const float*)input,frameCount);
}
class MicTranscriber{
    moonshine::Transcriber transcriber;
    ma_device_config config;
    ma_device device;
    bool running;
    bool init = false;
    
public:
    MicTranscriber(moonshine::TranscriptEventListener* e):MicTranscriber(){
        if(!init)return;
        transcriber.addListener(e);
    }
    MicTranscriber(std::function<void (const moonshine::TranscriptEvent&)> e):MicTranscriber(){
        if(!init)return;
        transcriber.addListener(e);
    }
    MicTranscriber():transcriber("models/english", moonshine::ModelArch::MEDIUM_STREAMING, 0.0),config(ma_device_config_init(ma_device_type_capture)),running(false){
        config.capture.format   = ma_format_f32;
        config.capture.channels = 1;
        config.sampleRate       = 16000;
        config.dataCallback     = data_callback;
        config.pUserData        = &transcriber;
        if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
            std::cerr << "Failed to init mic\n";
            return;
        }
        init = true;
    }
    ~MicTranscriber(){
        Stop();
        ma_device_uninit(&device);
    }
    std::string GetLine(){
        if(!init)return;
        
    }
    void addListener(moonshine::TranscriptEventListener* e){
        transcriber.addListener(e);
    }
    void addListener(std::function<void (const moonshine::TranscriptEvent&)> e){
        transcriber.addListener(e);
    }
    void removeListener(moonshine::TranscriptEventListener* e){
        transcriber.removeListener(e);
    }
    void removeListener(std::function<void (const moonshine::TranscriptEvent&)> e){
        transcriber.removeListener(e);
    }
    void Start(){
        if(running)return;
        transcriber.start();
        ma_device_start(&device);
        running = true;
    }
    void Stop(){
        if(!running)return;
        transcriber.stop();
        ma_device_stop(&device);
        running = false;
    }
};