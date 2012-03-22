//
//  TT_Sequencer_Quiet.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 22/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_Sequencer_Quiet_h
#define particles_3d_5_TT_Sequencer_Quiet_h

#pragma once
//#include "TT_Sequencer.h"
#include "TT_SequencerSettings.h"

class TT_Sequencer_Quiet : public TT_SequencerSettings {

private:
    
    void makeGentlePush()
    {
        if ( ofRandom(0,1) > prob ) {
            triggerForceEvent();
            triggerBoxFlashEvent();
        }
    }
    
public:
    
    TT_Sequencer_Quiet()
    {
        prob = .7;
    }
    
    //-------------------------------------------------------------------  Event Listeners
    void onQuarterNote( int &beats ) 
    {
        
    }
    
    //-------------------------------------------------------------------
    void onHalfNote( int &beats ) 
    {
        makeGentlePush();
    }
    
    //-------------------------------------------------------------------
    void onFullNote( int &beats )
    {
        
    }

};



#endif
