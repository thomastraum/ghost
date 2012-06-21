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
    
protected:
    
    vector<Physics::Particle3D*>        collided_particles;
    bool                                fresh_cache;
    
public:
    
    MSAParticleSystemEvented() {
        ofAddListener( PGravEventDispatcher,this,&MSAParticleSystemEvented::onPGravEvent );
        ofAddListener( CollisionEventDispatcher,this,&MSAParticleSystemEvented::onCollisionEvent );
        
        ofAddListener( AddUpdaterEventDispatcher,this,&MSAParticleSystemEvented::onAddUpdater );
        ofAddListener( RemoveUpdaterEventDispatcher,this,&MSAParticleSystemEvented::onRemoveUpdater );
        
    }
    
    void onPGravEvent( PGravEvent & args )
    {
        ofLogNotice( "TT" ) << " gravity: " << args.gravity;
        gravity = args.gravity;
    }
    
    void onCollisionEvent( CollisionEvent & args )
    {
        cacheCollided( args.p );
        fresh_cache = true;
    }
    
    void cacheCollided( Physics::Particle3D * p )
    {
        collided_particles.push_back(p);
    }

    void onAddUpdater( AddUpdaterEvent & e )
    {
        ofLogNotice( "TT-NI" ) << "MSAParticleSystemEvented::onAddUpdater";
        addUpdater( e.updater );
    }
    
    void onRemoveUpdater( RemoveUpdaterEvent & e )
    {
//        removeUpdater( e.updater);
    }
    
    void update()
    {
        MSAParticleSystem3D_Groups::update();
        
        if (fresh_cache) {
			for ( vector<Physics::Particle3D*>::iterator it = collided_particles.begin(); it != collided_particles.end(); it++) {
                Physics::Particle3D * p = *it;
                // pos, how many, emitsize, speed //
                addLines( p->getPosition(), 5, Vec3f(40,40,40), p->getVelocity() + Vec3f(0,0,ofRandom(-1000,1000)) );
                addCollided( p->getPosition(),10, Vec3f(40,40,40), Vec3f(0,0,0) );
                p->kill();
//                p->setSize(
            }
            collided_particles.clear();
            fresh_cache = false;
        }
    }
    
};

#endif
