#include "include/moonshine-cpp.h"

class Procceser : public moonshine::TranscriptEventListener{
public:
    Procceser(){

    }
    void onLineCompleted(const moonshine::LineCompleted &event) override{

    }
    void onLineStarted(const moonshine::LineStarted &event) override{
        
    }
    void onLineUpdated(const moonshine::LineUpdated &event) override{
        
    }
    void onLineTextChanged(const moonshine::LineTextChanged &event) override{
        
    }
};