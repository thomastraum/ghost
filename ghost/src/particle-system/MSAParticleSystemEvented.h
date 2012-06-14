//
//  MSAParticleSystemEvented.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 22/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_MSAParticleSystemEvented_h
#define particles_3d_5_MSAParticleSystemEvented_h


#pragma once
#include "ofMain.h"
#include "AppEvents.h"
#include "MSAParticleSystem3D_Groups.h"

class MSAParticleSystemEvented : public MSAParticleSystem3D_Groups {
    
public:
    
    MSAParticleSystemEvented() {
        ofAddListener( PGravEventDispatcher,this,&MSAParticleSystemEvented::onPGravEvent );
        ofAddListener( CollisionEventDispatcher,this,&MSAParticleSystemEvented::onCollisionEvent );
    }
    
    void onPGravEvent( PGravEvent & args )
    {
        ofLogNotice( "TT" ) << " gravity: " << args.gravity;
        gravity = args.gravity;
    }
    
    
    void onCollisionEvent( CollisionEvent & args )
    {
//        ofLogNotice("TT") << " event collision " << args.position;
        addCollided( Vec3f( args.position.x, args.position.y, args.position.z ),10, Vec3f(10,10,10) ); 
    }
    
};


#endif
