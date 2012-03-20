//
//  TT_SoundManager.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 19/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_SoundManager_h
#define particles_3d_5_TT_SoundManager_h

#pragma once 
#include "ofMain.h"
#include "TT_SoundPlayer.h"

class TT_SoundManager {
    
    vector<TT_SoundPlayer*> loops;
    vector<ofSoundPlayer*>  event_sounds;
    
public:
    
    TT_SoundManager()
    {
        
    }
    
    //--------------------------------------------
    void addLoop( string _path )
    {
        TT_SoundPlayer * loop = new TT_SoundPlayer();
        loop->loadSound( _path );
        loops.push_back( loop );
    }
    
    //-------------------------------------------- 
    void addEventSound( string _path )
    {
        ofSoundPlayer * event_sound = new ofSoundPlayer();
        event_sound->loadSound( _path );
        event_sounds.push_back( event_sound );
    }
    
    
    //--------------------------------------------
    void fadeLoopVolume( int _id, float _volume, float _duration=0.5 )
    {
        cout << "fadeLoopVolume id: " << _id << " v: " << _volume << " d: " << _duration << endl;
        loops[_id]->fadeVolume( _volume, _duration );
    }
    
    //-------------------------------------------- 
    
    // Add custom event system, where we listen for events and decide which one we play
    // new user event
    //  loop through event sounds
    // 
    
    
protected:
    
    
};

#endif
