//
//  TT_FogAnimated.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 23/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_FogAnimated_h
#define particles_3d_5_TT_FogAnimated_h

#pragma once
#include "AppEvents.h"
#include "TT_Fog.h"
#include "TT_Timer.h"

class TT_FogAnimated : public TT_Fog {
    
    
public:
    
    ofFloatColor    start;
    ofFloatColor    target;
    ofFloatColor    old;
    TT_Timer        timer;
    
protected:
    
    //---------------------------------------------------------------
    void setColTarget( ofFloatColor _target )
    {
        
        if ( timer.isTimerRunning() ) {
            target = _target;
        } else {
            start   = getColor();
            target  = _target;
        }
    }
    
public:
    
    TT_FogAnimated()
    {
//        ofAddListener( timer.onTimerUpdated,this,&TT_FogAnimated::onTimerUpdated );
        ofAddListener( FogFlashEventDispatcher,this,&TT_FogAnimated::onFogFlashEvent );
    }
    
    //---------------------------------------------------------------
    void fadeToColor( ofFloatColor _col, float _duration )
    {
        setColTarget( _col );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
        
        ofRemoveListener( timer.onTimerUpdated,this,&TT_FogAnimated::onTimerUpdatedBackAndForth );
        ofAddListener( timer.onTimerUpdated,this,&TT_FogAnimated::onTimerUpdated );
    };
    
    //---------------------------------------------------------------
    void flashUp( ofFloatColor _col, float _duration )
    {
        setColTarget( _col );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
        
        ofRemoveListener( timer.onTimerUpdated,this,&TT_FogAnimated::onTimerUpdated );
        ofAddListener( timer.onTimerUpdated,this,&TT_FogAnimated::onTimerUpdatedBackAndForth );
    }
    
    //---------------------------------------------------------------
    void onTimerUpdated( float &p )
    {
        setColor( start.getLerped(target, p) );
    }
    
    //---------------------------------------------------------------
    void onTimerUpdatedBackAndForth( float &p )
    {
        setColor( start.getLerped(target, sin(PI*p)) );
    }
    
    void onFogFlashEvent( FogFlashEvent & args )
    {
        ofLogNotice("TT") << "TT_FogAnimated::onFogFlashEvent " << endl;
        flashUp( args.color, args.duration );
    }
    
    
};



#endif
