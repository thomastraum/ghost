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
#include "TT_PlayerEvents.h"
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
        
        ofAddListener( ParticleBurstEventDispatcher,this,&MSAParticleSystemEvented::onParticleBurst );
        
//        ofAddListener( TT_UserLostEventDispatcher,this,&MSAParticleSystemEvented::onUserDeleted );
//        ofAddListener( TT_NewUserDispatcher,this,&MSAParticleSystemEvented::onUserCreated );
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
//        addQuads( Vec3f( 0,0,0 ), 2000, Vec3f(width,height,height*2), Vec3f( 100,100,100) );
    }
    
    void onRemoveUpdater( RemoveUpdaterEvent & e )
    {
//        removeUpdater( e.updater);
    }

    void onParticleBurst( ParticleBurstEvent & e )
    {
        addLines( e.pos, e.count, e.range, e.speed );
        
    }
    
    void update()
    {
        MSAParticleSystem3D_Groups::update();
        
        if (fresh_cache) {
			for ( vector<Physics::Particle3D*>::iterator it = collided_particles.begin(); it != collided_particles.end(); it++) {
                Physics::Particle3D * p = *it;
                // pos, how many, emitsize, speed //
                
                if(ofRandom(1) < 1 ) {
                   addLines( p->getPosition(), 1, Vec3f(0,0,0), p->getVelocity() + Vec3f(100,100,250) );
                }
                addCollided( p->getPosition(),1, Vec3f(10,10,10), Vec3f(100,100,100) ); //Vec3f(0,0,0) );
//                p->kill();
            }
            collided_particles.clear();
            fresh_cache = false;

        }
    }
    
};

#endif
