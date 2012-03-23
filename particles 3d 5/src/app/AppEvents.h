//
//  AppEvents.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 21/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_AppEvents_h
#define particles_3d_5_AppEvents_h

#pragma once
#include "ofMain.h"
#include "ofEvents.h"

class ForceEvent {

public:
    
    int     force_id;
    float   strength;
    float   duration;
    
    ForceEvent( int _id, float _strength, float _duration ): force_id( _id ), strength( _strength ), duration(_duration) {}
};

class LoopEvent {    
    
public:
    
    int     sound_id;
    float   volume;
    float   pan;
    float   duration;
    
    LoopEvent( int _id, float _volume, float _pan, float _duration ) 
        : sound_id(_id), volume(_volume), pan(_pan), duration(_duration) {}
};

class SoundFxEvent {    
    
public:
    
    int     sound_id;
    float   volume;
    float   duration;
    
    SoundFxEvent( int _id, float _volume, float _duration ): 
        sound_id( _id ), volume( _volume ), duration(_duration) {}
};

class EmitParticlesEvent {    
    
public:
    
    int     emitter_id;
    float   amount;
    
    EmitParticlesEvent( int _id, float _amount ): emitter_id( _id ), amount( _amount ) {}
};

class BoxFlashEvent {    
    
public:
    
    ofFloatColor    color;
    float           duration;
    
    BoxFlashEvent( ofFloatColor _color, float _duration ): color( _color ), duration( _duration ) {}
};

class FogFlashEvent {    
    
public:
    
    ofFloatColor    color;
    float           duration;
    
    FogFlashEvent( ofFloatColor _color, float _duration ): color( _color ), duration( _duration ) {}
};


class PGravEvent {    
    
public:
    
    float   gravity;
    
    PGravEvent( float _gravity ): gravity( _gravity ) {}
    
};

extern ofEvent<ForceEvent>          ForceEventDispatcher;
extern ofEvent<LoopEvent>           LoopEventDispatcher;
extern ofEvent<SoundFxEvent>        SoundFxEventDispatcher;
extern ofEvent<EmitParticlesEvent>  EmitParticlesEventDispatcher;
extern ofEvent<BoxFlashEvent>       BoxFlashEventDispatcher;
extern ofEvent<FogFlashEvent>       FogFlashEventDispatcher;
extern ofEvent<PGravEvent>          PGravEventDispatcher;

#endif
