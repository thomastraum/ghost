//
//  msaPhysicsUpdater.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 03/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once
#include "MSAPhysics3D.h"
//#include "TT_Custom_MSAParticle3D.h"

using namespace MSA;

class MSAPhysicsUpdater3D : public Physics::ParticleUpdater3D {
    
public:
    
    MSAPhysicsUpdater3D(){};
    
    virtual void update( Physics::Particle3D * _p ) 
    {
        
    }
    void setWindowSize( Vec2f  _windowSize );
    
    Vec2f   invWindowSize;
    Vec2f   windowSize;
    
};