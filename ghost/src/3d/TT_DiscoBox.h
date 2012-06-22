//
//  TT_DiscoBox.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 19/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_DiscoBox_h
#define particles_3d_5_TT_DiscoBox_h

#pragma once
#include "ofMain.h"
#include "TT_BoxGui.h"
#include "TT_Timer.h"

class TT_DiscoBox : public TT_BoxGui {
    
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
    
    TT_DiscoBox()
    {
//        ofAddListener( timer.onTimerUpdated,this,&TT_DiscoBox::onTimerUpdated );
    }

    //---------------------------------------------------------------
    void fadeToColor( ofFloatColor _col, float _duration )
    {
        cout << "color" << _col;
        
        setColTarget( _col );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
        
        ofRemoveListener( timer.onTimerUpdated,this,&TT_DiscoBox::onTimerUpdatedBackAndForth );
        ofAddListener( timer.onTimerUpdated,this,&TT_DiscoBox::onTimerUpdated );
    };
    
    //---------------------------------------------------------------
    void flashUp( ofFloatColor _col, float _duration )
    {
        setColTarget( _col );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
        
        ofRemoveListener( timer.onTimerUpdated,this,&TT_DiscoBox::onTimerUpdated );
        ofAddListener( timer.onTimerUpdated,this,&TT_DiscoBox::onTimerUpdatedBackAndForth );
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
};


#endif
