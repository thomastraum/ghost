//
//  TT_SoundPlayer.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 13/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_SoundPlayer_h
#define particles_3d_5_TT_SoundPlayer_h

#pragma once
#include "ofMain.h"
#include "ofEvents.h"
#include "TT_Timer.h"

using namespace MSA;

//-----------------------------
// Good for loop sounds only
//-----------------------------

class TT_SoundPlayer {
    
    int     volume;
    float   pan;
    
    TT_Timer   vol_timer;
    TT_Timer   pan_timer;
    
    float vol_target, vol_start;
    float pan_target, pan_start;
    
protected:
    
    ofSoundPlayer   sound;
    
    //---------------------------------------------------------------
    void setVolTarget( float _target )
    {
        vol_start = vol_target;
        vol_target = _target;
    }
    
    //---------------------------------------------------------------
    void setPanTarget( float _target )
    {
        pan_start = pan_target;
        pan_target = _target;
    }
    
public:
    
    TT_SoundPlayer()
    {
        vol_target = vol_start = 1;
        pan_target = pan_start = 0.5;
        
	    ofAddListener(pan_timer.onTimerUpdated, this, &TT_SoundPlayer::updatePan);
	    ofAddListener(vol_timer.onTimerUpdated, this, &TT_SoundPlayer::updateVolume);
    }
    
    //---------------------------------------------------------------
    void updatePan( float &p ) 
    {
        sound.setPan( pan_start + ((pan_target-pan_start) * p) );
    }
    
    //---------------------------------------------------------------
    void updateVolume( float &p ) 
    {
//        cout << "updateVolume " << vol_timer.getSeconds() << " p: " << p << endl;
//        cout << "vol_start " << vol_start << " vol_target " << vol_target << endl;
        sound.setVolume( vol_start + ((vol_target-vol_start) * p) );
    }
    
    //---------------------------------------------------------------
    void draw()
    {
//        ofRect(20,350,200,20);
    }
    
    //---------------------------------------------------------------
    void loadSound( string _path_to_sound )
    {
        sound.loadSound( _path_to_sound );
        sound.play();
        sound.setLoop( true );
        sound.setPan(0.01);
    }
    
    //---------------------------------------------------------------
    void fadePan( float _pan, float _duration ) 
    {
        setPanTarget( _pan );
        
        pan_timer.stopTimer();
        pan_timer.setDuration( _duration );
        pan_timer.startTimer();
    }
    
    //---------------------------------------------------------------
    void fadeVolume( float _volume, float _duration )
    {
        setVolTarget( _volume );
        
        vol_timer.stopTimer();
        vol_timer.setDuration( _duration );
        vol_timer.startTimer();
    };
    
    //---------------------------------------------------------------
    void setVolume( float _vol )
    {
        vol_timer.stopTimer();
        
        setVolTarget( _vol );
        sound.setVolume(_vol);
        cout << "_vol: " << _vol << endl;
    }
    
    //---------------------------------------------------------------
    void setPanning( float _pan )
    {
        cout << "_pan: " << _pan << endl;
        pan_timer.stopTimer();
        
        setPanTarget( _pan );
        sound.setPan(_pan);
    }

    
};

//  OLD
////---------------------------------------------------------------
//void update() 
//{
//    if( vol_timer.isTimerRunning() ) {
//        sound.setVolume( vol_start + ((vol_target-vol_start) * vol_timer.getDiffN()) );
//    }
//    
//    if( pan_timer.isTimerRunning() ) {
//        sound.setPan( pan_start + ((pan_target-pan_start) * pan_timer.getDiffN()) );            
//        cout << "_pan: " << sound.getPan() << endl;
//    }
//    
//}

#endif
