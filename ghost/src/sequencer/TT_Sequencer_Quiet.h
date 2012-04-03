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
        if ( ofRandom(1) < 0.5 ) { 
            ForceEvent event = ForceEvent(floor(ofRandom(0,2) ), 0.03, 4 );
            ofNotifyEvent(ForceEventDispatcher, event);
        } else {
            ForceEvent event = ForceEvent( floor(ofRandom(2,4)), 0.01, 1.5 );
            ofNotifyEvent(ForceEventDispatcher, event);
        }
        
        SoundFxEvent fx = SoundFxEvent( floor(ofRandom(0,3)), 1,1 );
        ofNotifyEvent(SoundFxEventDispatcher, fx);
        
        makeDiscoSoundBeat();
        changeGravNice();
    }
    
    void makeBigPush()
    {
        cout << "big push" << endl;
        
        if ( ofRandom(0,1) > 0.6 ) {
            ForceEvent event = ForceEvent( floor(ofRandom(0,4)), ofRandom(0.7,2), .5 );
            ofNotifyEvent(ForceEventDispatcher, event);
            
            SoundFxEvent snd = SoundFxEvent( floor(ofRandom(4,7)), 1, 1 );
            ofNotifyEvent(SoundFxEventDispatcher, snd);
            
            ofColor c;
            c.setHsb(0, 255, 255);
            c.setHue( (int)ofRandom(255) ) ;
            BoxFlashEvent flash = BoxFlashEvent( c, 1 );
            ofNotifyEvent(BoxFlashEventDispatcher, flash);
            
            PGravEvent rise = PGravEvent( ofRandom( 1, 3) );
            ofNotifyEvent( PGravEventDispatcher, rise );
            
            ofColor f = ofFloatColor( .8 + ofRandom(0,.2), .8 + ofRandom(0,.2), .8 + ofRandom(0,.2) );
            FogFlashEvent fog_flash = FogFlashEvent( f, 1 );
            ofNotifyEvent( FogFlashEventDispatcher, fog_flash );
        }
    }
    
    void makeMediumPush()
    {
        if (  ofRandom(1) < 0.5) { 
            ForceEvent event = ForceEvent(floor(ofRandom(0,2) ), 0.2, 4 );
            ofNotifyEvent(ForceEventDispatcher, event);
        } else {
            ForceEvent event = ForceEvent( floor(ofRandom(2,4)), 0.02, 2 );
            ofNotifyEvent(ForceEventDispatcher, event);
        }
        
        ofColor c = ofFloatColor( .8 + ofRandom(0,.2), .8 + ofRandom(0,.2), .8 + ofRandom(0,.2) );
        BoxFlashEvent flash = BoxFlashEvent( c, 1 );
        ofNotifyEvent(BoxFlashEventDispatcher, flash);
        
        ofColor f = ofFloatColor( ofRandom(0,.1), ofRandom(0,.1), ofRandom(0,.1) );
        FogFlashEvent fog_flash = FogFlashEvent( f, 3 );
        ofNotifyEvent( FogFlashEventDispatcher, fog_flash );
        
        PGravEvent grav = PGravEvent( ofRandom(-2,2) );
        ofNotifyEvent( PGravEventDispatcher, grav );
        
    }
    
    void makeLoopChange()
    {
//        l_para.volume = ofRandom(0.2,1);
        
        LoopEvent loop_nice = LoopEvent( 1, ofRandom(0.2,1), .5, 0 );
        ofNotifyEvent( LoopEventDispatcher, loop_nice );
        
        // fade stormy loop down.
        LoopEvent loop_storm = LoopEvent( 0,  ofRandom(0,0.2), .5, 0 );
        ofNotifyEvent( LoopEventDispatcher, loop_storm );
        
    }
    
    void makeLoopChangeStormy()
    {
        LoopEvent loop_storm = LoopEvent( 0, ofRandom(0.3,1), .5, 0 );
        ofNotifyEvent( LoopEventDispatcher, loop_storm );
        
        // fade nice loop down.
        LoopEvent loop_nice = LoopEvent( 1, ofRandom(0,0.1), .5, 0 );
        ofNotifyEvent( LoopEventDispatcher, loop_nice );
        
    }
    
    void changeGravNice()
    {
        PGravEvent grav = PGravEvent( ofRandom(-0.1,.5) );
        ofNotifyEvent( PGravEventDispatcher, grav );       
    }

    void makeDiscoSoundBeat()
    {
        ofFloatColor c = ofFloatColor( ofRandom(.8,1), ofRandom(.8,1), ofRandom(.8,1), 1 );
        
//        ofFloatColor c = ofFloatColor( ofRandom(0, 1),ofRandom(0, 1),ofRandom(0, 1));
//        c.setHsb( ofRandom(0,1), 1, 1 );
//        c.setHsb(0,128,255);
//        c.setHue( (int)ofRandom(255) );
//        c.setSaturation( (int)ofRandom(255) ); 
        
        BoxFlashEvent event = BoxFlashEvent( c, 2 );
        ofNotifyEvent(BoxFlashEventDispatcher, event);
        
        SoundFxEvent fx = SoundFxEvent( 3, 1, 1 );
        ofNotifyEvent(SoundFxEventDispatcher, fx);
        
    }
    
public:
    
    TT_Sequencer_Quiet()
    {
        prob = .7;
        burstprob = .95;
    }
    
    //-------------------------------------------------------------------  Event Listeners
    void onQuarterNote( int &beats ) 
    {

    }
    
    //-------------------------------------------------------------------
    void onHalfNote( int &beats ) 
    {
        if ( ofRandom(0,1) > prob ) {
            makeGentlePush();
        }
        if ( ofRandom(0,1) > burstprob ) {
            makeLoopChangeStormy();
            makeMediumPush();
        }
    }
    
    //-------------------------------------------------------------------
    void onFullNote( int &beats )
    {
        if ( ofRandom(0,1) > prob ) {
            makeLoopChange();
        }
        
        if ( ofRandom(0,1) > burstprob ) {
            makeBigPush();
        }
    }

};



#endif
