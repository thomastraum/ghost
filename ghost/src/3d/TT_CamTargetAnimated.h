//
//  TT_CamTargetAnimated.h
//  ghost
//
//  Created by Thomas Eberwein on 24/04/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_TT_CamTargetAnimated_h
#define ghost_TT_CamTargetAnimated_h

#pragma once
#include "TT_CamTarget_Vibrate.h"
#include "TT_Timer.h"
#include "AppEvents.h"

class TT_CamTargetAnimated : public TT_CamTarget_Vibrate {
    
public:
    
    float           start;
    float           target;
    float           old;
    TT_Timer        timer;
    
protected:
    
    //---------------------------------------------------------------
    void setAmplitudeTarget( float _target )
    {
        if ( timer.isTimerRunning() ) {
            target = _target;
        } else {
            start   = getAmplitude();
            target  = _target;
        }
    }
    
public:
    
    TT_CamTargetAnimated()
    {
        ofAddListener( CamTargetAnimateEventDispatcher,this,&TT_CamTargetAnimated::onCamTargetAnimateEvent );
        ofAddListener( timer.onTimerUpdated,this,&TT_CamTargetAnimated::onTimerUpdatedBackAndForth );
    }
    
    //---------------------------------------------------------------
    void animate( float _amp, float _freq, float _duration )
    {
        setAmplitudeTarget( _amp );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
        
    }
    
    //---------------------------------------------------------------
    void onTimerUpdatedBackAndForth( float &p )
    {
        setAmplitude( start + ((target-start) * sin(PI*p)) );
    }
    
    void onCamTargetAnimateEvent( CamTargetAnimateEvent & args )
    {
        cout << "TT_CamTargetAnimated::onAnimateEvent " << endl;
        animate( args.amp, args.freq, args.duration );
    }
    
};


#endif
