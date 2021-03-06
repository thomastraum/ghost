//
//  sinewaveforce.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 07/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once
//#include "baseforce.h"
#include "BaseForceAnimated.h"
#include "MSATimer.h"

class SineWaveForce : public BaseForceAnimated {
    
public:
    
    void setup( MSAFluidManager * manager );
    void update();
    
    void addSettings( ofxSimpleGuiToo &_gui);
    
protected:
    
    Timer timer;
    float freq, offset;
    
};