//
//  sinewaveforce.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 07/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once
#include "baseforce.h"

class SineWaveForce : public BaseForce {
    
public:
    
    SineWaveForce(){
        BaseForce();
        classname = "SineWaveForce";
    };
    
    virtual void update();
    virtual void draw();
    
    void addSettings( string _instance_name, ofxSimpleGuiToo &_gui);
    
protected:
    
    float freq, offset;
    
};