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
#include "ofEvents.h"
#include "TT_Tempo.h"

class TT_Sequencer {
    
    TT_Tempo    tempo;
    
public:

    void TT_Sequencer() {
        
		ofAddListener(ofEvents.onQuarterNote,this,&TT_Sequencer::onQuarterNote);
		ofAddListener(ofEvents.onHalfNote,this,&TT_Sequencer::onHalfNote);
		ofAddListener(ofEvents.onFullNote,this,&TT_Sequencer::onFullNote);
        
    }
    
    void onQuarterNote( float &beats )
    {
        
    }
    
    void onHalfNote( float &beats )
    {
        
    }
    
    void onFullNote( float &beats )
    {
        
    }
    
};


#endif
