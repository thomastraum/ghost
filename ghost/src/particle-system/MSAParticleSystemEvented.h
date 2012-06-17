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
    
    vector<Vec3f>   collided_cache_pos;
    bool            fresh_cache;
    
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
//        addCollided( Vec3f( args.position.x, args.position.y, args.position.z ),10, Vec3f(10,10,10) ); 
        
        cacheCollided( Vec3f( args.position.x, args.position.y, args.position.z ) );
        fresh_cache = true;
        
    }
    
    void cacheCollided( Vec3f _pos )
    {
        collided_cache_pos.push_back(_pos);
    }

    void update()
    {
        MSAParticleSystem3D_Groups::update();
        
        if (fresh_cache) {
			for ( vector<Vec3f>::iterator it = collided_cache_pos.begin(); it != collided_cache_pos.end(); it++) {
                Vec3f pos = *it;
                addCollided( pos,1, Vec3f(0,0,0), Vec3f( 100,100,1000) ); 
            }
            collided_cache_pos.clear();
            fresh_cache = 0;
        }
    }
    
};



#endif
