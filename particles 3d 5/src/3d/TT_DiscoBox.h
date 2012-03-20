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

class TT_DiscoBox : public TT_Box {
    
    ofFloatColor    start;
    ofFloatColor    target;
    ofFloatColor    old;
    TT_Timer        timer;
    
protected:
    
    //---------------------------------------------------------------
    void setColTarget( ofFloatColor _target )
    {
        start   = getColor();
        target  = _target;
    }
    
public:
    
    TT_DiscoBox()
    {
        ofAddListener( timer.onTimerUpdated,this,&TT_DiscoBox::onTimerUpdated );
    }

    //---------------------------------------------------------------
    void fadeToColor( ofFloatColor _col, float _duration )
    {
        setColTarget( _col );
        timer.stopTimer();
        timer.setDuration( _duration );
        timer.startTimer();
    };
    
    //---------------------------------------------------------------
    void flashUp( ofFloatColor _col, float _duration )
    {
        if ( timer.isTimerRunning() ) return;
        
        fadeToColor( _col, _duration);
        ofRemoveListener( timer.onTimerFinished,this,&TT_DiscoBox::onTimerFinished );
        ofAddListener( timer.onTimerFinished,this,&TT_DiscoBox::onTimerFinished );
    }
    
    //---------------------------------------------------------------
    void onTimerUpdated( float &p )
    {
        setColor( start.getLerped(target, p) );
    }
    
    //--------------------------------------------------------------- EVENT
    void onTimerFinished( float &_duration )
    {
        cout << "onTimerFinished " << _duration << endl;
        ofRemoveListener(timer.onTimerFinished,this,&TT_DiscoBox::onTimerFinished);
        fadeToColor( start,  _duration );
    }
};


#endif
