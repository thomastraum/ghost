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
//            f_para.force_id = floor(ofRandom(0,4));
//            triggerForceEvent();
            
            
            if (  ofRandom(1) < 0.5) { 
                ForceEvent event = ForceEvent(floor(ofRandom(0,2) ), 0.03, 6 );
                ofNotifyEvent(ForceEventDispatcher, event);
            } else {
                ForceEvent event = ForceEvent( floor(ofRandom(2,4)), 0.01, 3 );
                ofNotifyEvent(ForceEventDispatcher, event);
            }
            
            s_para.sound_id = floor(ofRandom(0,3));
            s_para.volume = 1;
            triggerSoundFxEvent();
            
            makeDiscoSoundBeat();
            changeGravNice();
        }
    }
    
    void makeBigPush()
    {
        if ( ofRandom(0,1) > .95 ) {
            
            cout << "big push" << endl;
            
            ForceEvent event = ForceEvent( floor(ofRandom(0,4)), ofRandom(0.7,2), 1 );
            ofNotifyEvent(ForceEventDispatcher, event);
            
            SoundFxEvent snd = SoundFxEvent( floor(ofRandom(4,7)), 1, 1 );
            ofNotifyEvent(SoundFxEventDispatcher, snd);
            
            BoxFlashEvent flash = BoxFlashEvent( ofColor::red, 1 );
            ofNotifyEvent(BoxFlashEventDispatcher, flash);
            
            PGravEvent rise = PGravEvent( ofRandom( 1, 3) );
            ofNotifyEvent( PGravEventDispatcher, rise );
        }
    }
    
    void makeLoopChange()
    {
        l_para.volume = ofRandom(0.2,1);
        triggerLoopEvent();
        
        // fade stormy loop down.
        l_para.sound_id = 0;
        l_para.volume = ofRandom(0,0.2);
        triggerLoopEvent();
    }
    
    void changeGravNice()
    {
        if ( ofRandom(0,1) > prob ) {
            pgrav_para.gravity = ofRandom(0.2,1);
            triggerPGravEvent();
        }
    }

    void makeDiscoSoundBeat()
    {
        triggerBoxFlashEvent();
        
        s_para.sound_id = 3;
        s_para.volume = 1;
        triggerSoundFxEvent();
        
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
        makeBigPush();
        
    }

};



#endif
