//
//  TT_UserEvents.h
//  ghost
//
//  Created by Thomas Eberwein on 21/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_TT_UserEvents_h
#define ghost_TT_UserEvents_h

#pragma once
#include "TT_User.h"
#include "ofEvents.h"
#include "TT_JointParticle.h"

//--------------------------------------------------------------
class TT_NewJointParticleEvent {
    
public:
    
    TT_JointParticle * p;
    TT_NewJointParticleEvent( TT_JointParticle * _p ):p(_p){}
    
};

extern ofEvent<TT_NewJointParticleEvent> TT_NewJointParticleEventDispatcher;


//--------------------------------------------------------------
class TT_RemoveJointParticleEvent {
    
public:
    
    TT_JointParticle * p;
    TT_RemoveJointParticleEvent( TT_JointParticle * _p ):p(_p){}
    
};

extern ofEvent<TT_RemoveJointParticleEvent> TT_RemoveJointParticleEventDispatcher;

#endif
