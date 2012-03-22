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
            
            // pick a random force //
            f_para.force_id = floor(ofRandom(0,4));
            triggerForceEvent();
            
//            ofColor col = ofColor::fromHsb(128, 255, 255); //b_para.color.getHsb();
//            col.setHue( ofRandom(0,0.1) );
//            b_para.color = col;
            
            triggerBoxFlashEvent();
        }
    }
    
    void makeLoopChange()
    {
        l_para.volume = ofRandom(1);
        triggerLoopEvent();
    }
    
    void changeGrav()
    {
        pgrav_para.gravity = ofRandom(-1,1);
        triggerPGravEvent();
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
        makeLoopChange();
        changeGrav();
    }

};



#endif
