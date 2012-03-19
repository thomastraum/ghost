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
    ofFloatColor    temp;
    TT_Timer        timer;
    
protected:
    
    //---------------------------------------------------------------
    void setColTarget( ofFloatColor _target )
    {
        start   = getColor();
        target  = _target;
        timer.stop();
    }
    
public:
    
    TT_DiscoBox()
    {
        
    }
    
    //---------------------------------------------------------------
    void update() 
    {
        if( timer.isTimerRunning() ) {
            timer.update();
            setColor( start.getLerped(target, timer.getDiffN()) );
        }
    }
    
    //---------------------------------------------------------------
    void fadeToColor( ofFloatColor _col, float _duration, float delay=0.0 )
    {
        setColTarget( _col );
        timer.setDuration( _duration );
        timer.start();
    };
    
    //---------------------------------------------------------------
    void flashUp( ofFloatColor _col, int _duration )
    {
        setColTarget( _col );
        timer.setDuration( _duration );
        timer.start();    }
    
};


#endif
