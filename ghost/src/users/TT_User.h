//
//  TT_User.h
//  ghost
//
//  Created by Thomas Eberwein on 27/04/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "MSAPhysicsUpdaterCollision.h"
#include "TT_Custom_MSAParticle3D.h"

class TT_User : public ofNode {

    vector<TT_Custom_MSAParticle3D*>    joint_particles;
    MSAPhysicsUpdaterCollision *        updater;
    
public:
    
    TT_User() {
        updater = 0;
    }
    
    void update()
    {
        if ( updater ) updater->checkCollisionWithThese( &joint_particles );
    }
    
    
    void addCollisionUpdater( MSAPhysicsUpdaterCollision * _updater )
    {
        updater = _updater;
    }
    
    void addJointParticle( TT_Custom_MSAParticle3D * _p )
    {
        joint_particles.push_back( _p );
    }
    
    void customDraw()
    {
        
    }
    
    
};
