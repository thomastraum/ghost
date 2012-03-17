//
//  TT_SoundManager.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 13/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_SoundManager_h
#define particles_3d_5_TT_SoundManager_h

#pragma once
#include "ofMain.h"
#include "ofxTween.h"
#include "TT_Timer.h"

using namespace MSA;

class TT_SoundManager {
    
    int     volume;
    float   pan;
    
    TT_Timer   vol_timer;
    TT_Timer   pan_timer;
    
    float vol_target, vol_start;
    float pan_target, pan_start;
    
    
    ofSoundPlayer   sound;
    
//    vector<Timer * > timers;
    
public:
    
    void setup()
    {
        vol_target = vol_start = 1;
        pan_target = pan_start = 0.5;
    }
    
    void update() 
    {
        if( vol_timer.isTimerRunning() ) {
            vol_timer.update();
            sound.setVolume( vol_start + ((vol_target-vol_start) * vol_timer.getDiffN()) );
        }
        
        if( pan_timer.isTimerRunning() ) {
            pan_timer.update();
            sound.setPan( pan_start + ((pan_target-pan_start) * pan_timer.getDiffN()) );
            
            cout << "_pan: " << sound.getPan() << endl;
        }
        
//        cout << vol_timer.getSeconds() << endl;
        
    }
    
    void draw()
    {
//        ofRect(20,350,200,20);
    }
    
    
    void loadSound( string _path_to_sound )
    {
        sound.loadSound( _path_to_sound );
        sound.play();
        sound.setLoop( true );
        sound.setPan(0.01);
    }
    
    void changePanning( float _pan, float _duration ) 
    {
        setPanTarget( _pan );
        pan_timer.setDuration( _duration );
        pan_timer.start();
    }
            
    void changeVolume( int _volume, float _duration )
    {
        setVolTarget( _volume );
        vol_timer.setDuration( _duration );
        vol_timer.start();
    };
    
    void setVolume( float _vol )
    {
        setVolTarget( _vol );
        sound.setVolume(_vol);
        cout << "_vol: " << _vol << endl;
    }
    
    void setPanning( float _pan )
    {
        cout << "_pan: " << _pan << endl;
        setPanTarget( _pan );
        sound.setPan(_pan);
    }
    
protected:
    
    
    void setVolTarget( float _target )
    {
        vol_start = vol_target;
        vol_target = _target;
        
        vol_timer.stop();
    }
    
    void setPanTarget( float _target )
    {
        pan_start = pan_target;
        pan_target = _target;
        
        pan_timer.stop();
    }
    
};


#endif
