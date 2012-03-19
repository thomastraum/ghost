//
//  TT_Timer.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 16/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_Timer_h
#define particles_3d_5_TT_Timer_h

#pragma once
#include "MSATimer.h"

using namespace MSA;

class TT_Timer : public Timer {
    
    float duration;
    
public:
    
    void update()
    {
        if ( getDiffN() >= 1  ) {
            stop();
        }
    }
    
    void setDuration( float _duration )
    {
        duration = _duration;
    }
    
    bool isTimerRunning()
    {
        return isRunning;
    }
    
    float getDiffN() {
        return (float)getElapsedSeconds()/(float)duration;
    }
    
    
    
    
};



#endif
