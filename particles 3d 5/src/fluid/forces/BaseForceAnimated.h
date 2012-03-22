//
//  BaseForceAnimated.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 20/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_BaseForceAnimated_h
#define particles_3d_5_BaseForceAnimated_h

#pragma once
#include "baseforce.h"
#include "TT_Timer.h"
#include "ofEvents.h"

class BaseForceAnimated : public BaseForce {
    
    TT_Timer timer;
    
    float start;
    float target;
    
    void setFadeTarget( float _target )
    {
        start = strength;
        target = _target;
    }
    
public:
    
    BaseForceAnimated() 
    {
        start = 0;
        target = 0;
        
        ofAddListener( timer.onTimerUpdated,this,&BaseForceAnimated::onTimerUpdated );
    }
    
    //---------------------------------------------------------------
    void fadeForce( float _target, float _duration)
    {
        setFadeTarget( _target );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
//        enable( true );
        
    }
    
    //---------------------------------------------------------------
    void fadeForceUpAndDown( float _target, float _duration)
    {
        if ( timer.isTimerRunning() ) return;
        
        fadeForce( _target, _duration );

        ofRemoveListener( timer.onTimerFinished,this,&BaseForceAnimated::onTimerFinished );
        ofAddListener( timer.onTimerFinished,this,&BaseForceAnimated::onTimerFinished );

    }
    
    //---------------------------------------------------------------
    void onTimerUpdated( float &p )
    {
        strength = start + ((target-start) * p);
    }
    
    //--------------------------------------------------------------- 
    void onTimerFinished( float &_duration )
    {
        ofRemoveListener(timer.onTimerFinished,this,&BaseForceAnimated::onTimerFinished);
        fadeForce( start,  _duration );
    }
};



#endif
