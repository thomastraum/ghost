//
//  MSAPhysicsUpdaterShake.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 14/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//


#pragma once
#include "MSAPhysics3D.h"

#define STRENGTH 150

class MSAPhysicsUpdaterShake : public Physics::ParticleUpdater3D {
    
    int     strength;
    bool    shake_me;
    
public:
    
    MSAPhysicsUpdaterShake()
    {
        strength    = STRENGTH;
        shake_me    = false;
    }
    
    void update( Physics::Particle3D * _p ) 
    {
        if ( shake_me )
            _p->addVelocity( Vec3f( ofRandom( -strength, strength ), ofRandom( -strength, strength ), 0 ) );
    }
    
    void toggleShake()
    {
        shake_me != shake_me;
    }
                            
    bool isShaking()
    {
        return shake_me;
    }
    
    void startShaking()
    {
        shake_me = true;
    }
    
    void stopShaking()
    {
        shake_me = false;
    }
    
};