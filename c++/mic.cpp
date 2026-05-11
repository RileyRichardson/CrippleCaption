#include "mic.h"
void data_callback(ma_device* device, void* output, const void* input,ma_uint32 frameCount) {
    ((moonshine::Transcriber*)(device->pUserData))->addAudio((const float*)input,frameCount);
}

MicTranscriber::MicTranscriber(moonshine::TranscriptEventListener* p):transcriber("models/english", moonshine::ModelArch::MEDIUM_STREAMING, 0.0),config(ma_device_config_init(ma_device_type_capture)),running(false){
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
    transcriber.addListener(p);
}
MicTranscriber::~MicTranscriber(){
    Stop();
    ma_device_uninit(&device);
}
void MicTranscriber::Start(){
    if(running)return;
    transcriber.start();
    ma_device_start(&device);
    running = true;
}
void MicTranscriber::Stop(){
    if(!running)return;
    transcriber.stop();
    ma_device_stop(&device);
    running = false;
}