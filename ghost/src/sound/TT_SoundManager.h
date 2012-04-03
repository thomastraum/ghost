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
#include "AppEvents.h"
#include "TT_SoundPlayer.h"

class TT_SoundManager {
    
    vector<TT_SoundPlayer*> loops;
    vector<ofSoundPlayer*>  event_sounds;
    
public:
    
    TT_SoundManager()
    {
        ofAddListener( LoopEventDispatcher,this,&TT_SoundManager::onLoopChange );
        ofAddListener( SoundFxEventDispatcher,this,&TT_SoundManager::onSoundFxEvent );
    }
    
    //---------------------------------------------------------------- Managing
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
    
    //---------------------------------------------------------------- Events
    void onLoopChange( LoopEvent & args )
    {
//        ofLogNotice( "TT" ) << "TT_SoundManager::onLoopChange ";
        fadeLoopVolume( args.sound_id, args.volume, args.duration );
    }
    
    //---------------------------------------------------------------- 
    void onSoundFxEvent( SoundFxEvent & args )
    {
        ofLogNotice( "TT" ) << "TT_SoundManager::onSoundFxEvent ";
        playEventSound( args.sound_id, args.volume );
    }
    
    //---------------------------------------------------------------- Work the Sounds
    void fadeLoopVolume( int _id, float _volume, float _duration=0.5 )
    {
//        ofLogNotice( "TT" ) << "fadeLoopVolume id: " << _id << " v: " << _volume << " d: " << _duration;
        loops[_id]->fadeVolume( _volume, _duration );
    }
    
    //-------------------------------------------- 
    void playEventSound( int _id, float _volume )
    {
        ofSoundPlayer * snd =  event_sounds[_id];
        if ( !snd->getIsPlaying() ) {
            snd->play();
            snd->setVolume(_volume);
        }
        ofLogNotice( "TT" ) << "playEventSound id: " << _id << " v: " << _volume;
    }
    
    
protected:
    
    
};

#endif
