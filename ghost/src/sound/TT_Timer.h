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
#include "ofMain.h"
#include "MSATimer.h"
#include "ofEvents.h"

class TT_Timer : public MSA::Timer {
    
    float duration;
    
public:
    
    void update(ofEventArgs & args)
    {
        float diff = getDiffN();
        ofNotifyEvent( onTimerUpdated,  diff );
        
        if ( diff >= 1  ) {
            stopTimer();
            ofNotifyEvent(onTimerFinished, duration );
        }
    }
    
    void startTimer()
    {
        start();
	    ofAddListener(ofEvents().update, this, &TT_Timer::update);
	}
    
	void stopTimer()
    {
        stop();
	    ofRemoveListener(ofEvents().update, this, &TT_Timer::update);
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
        float p = (float)getSeconds()/(float)duration;
        return (p<1) ? p : 1;
    }
    
    //------------------------------------------------------- EVENTS
    ofEvent<float> onTimerFinished;
    ofEvent<float> onTimerUpdated;
        
};



#endif
