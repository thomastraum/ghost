//
//  TT_Sequencer.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 21/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_Sequencer_h
#define particles_3d_5_TT_Sequencer_h

#pragma once
#include "ofMain.h"
#include "ofEvents.h"
#include "AppEvents.h"
#include "TT_Tempo.h"

//----------------------------------------------------------------------
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//----------------------------------------------------------------------

class TT_Sequencer {
    
    //----------------------------------------------------------------------
protected:
    
    TT_Tempo    tempo;
    
    // General probability to be used in child classes
    float prob;
    float burstprob;
    
    //----------------------------------------------------------------------
public:
    
    TT_Sequencer() {
        ofAddListener(tempo.onQuarterNote,this,&TT_Sequencer::onQuarterNote);
        ofAddListener(tempo.onHalfNote,this,&TT_Sequencer::onHalfNote);
        ofAddListener(tempo.onFullNote,this,&TT_Sequencer::onFullNote);
    }
    
    void start()
    {
        tempo.start();
    }
    
    void stop()
    {
        tempo.stop();
    }
    
    void update()
    {
        tempo.update();
    }
    
    //-------------------------------------------------------------------   Virtual Event Listeners
    virtual void onQuarterNote( int &beats ) {}
    
    //-------------------------------------------------------------------
    virtual void onHalfNote( int &beats ) {}
    
    //-------------------------------------------------------------------
    virtual void onFullNote( int &beats ){}
    
};

#endif
