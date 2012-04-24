//
//  TT_CamTarget_Vibrate.h
//  ghost
//
//  Created by Thomas Eberwein on 23/04/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_TT_CamTarget_Vibrate_h
#define ghost_TT_CamTarget_Vibrate_h

#pragma once
#include "TT_CamTarget.h"

class TT_CamTarget_Vibrate : public TT_CamTarget {
    
protected:

    float amp;
    float freq;

private :

    float t;
    float tilt_amount, pan_amount, roll_amount;
    
public:
    
    TT_CamTarget_Vibrate() {
        freq    = 0.25;
        amp     = 7;
    }

    void update()
    {
        t = ofGetElapsedTimef() * freq;
        
        tilt_amount = -getRoll() - (ofSignedNoise(t, 0, 0)* amp);
        tilt(tilt_amount);
        
        pan_amount = -getHeading() - (ofSignedNoise(0, t, 0) * amp );
        pan(pan_amount);    
        
        roll_amount = -getPitch() - (ofSignedNoise(0, 0, t) * amp) * 0.1;
        roll(roll_amount);
    }
    
    virtual float   getAmplitude(){ return amp; }; 
    virtual void    setAmplitude( float _amp ){  amp = _amp; }; 

};



#endif
