//
//  MSAPhysicsUpdaterCollision.h
//  ghost
//
//  Created by Thomas Eberwein on 27/04/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofEvents.h"
#include "AppEvents.h"
#include "MSAPhysics3D.h"

using namespace MSA;

class MSAPhysicsUpdaterCollision : public Physics::ParticleUpdater3D {
    
    vector<Physics::Particle3D*>  colliders;
    Vec3f min;
    Vec3f max;
    
public:
    
    MSAPhysicsUpdaterCollision() {
        min = Vec3f( 0,0,0 );
        max = Vec3f( 0,0,0 );
    };
    
    virtual void update( Physics::Particle3D * _pA )
    {
        vector<Physics::Particle3D*>::iterator it = colliders.begin();
        
        while( it != colliders.end() ) {
            
            Physics::Particle3D * pB = *it;
            if ( checkCollisionBetween( _pA, pB ) ) {
                CollisionEvent e = CollisionEvent( _pA ); //, _pA, pB );
                ofNotifyEvent( CollisionEventDispatcher, e );
                break;
            }
            it++;
        }
        
    }
    
    void calculateBoundingBox()
    {
        Vec3f c_pos;
        Vec3f radius;
        
        Vec3f newmin;
        Vec3f newmax;
        
        vector<Physics::Particle3D*>::iterator it = colliders.begin();
        while( it != colliders.end() ) {
            Physics::Particle3D * c = *it;
            c_pos = c->getPosition();
            radius = Vec3f( c->getRadius(), c->getRadius(), c->getRadius() );
            
            newmin = c_pos - radius;
            newmax = c_pos + radius;
            
            if ( newmin.x < min.x ) min.x = newmin.x;
            if ( newmin.y < min.y ) min.y = newmin.y;
            if ( newmin.z < min.z ) min.z = newmin.z;
            
            if ( newmax.x > max.x ) max.x = newmax.x;
            if ( newmax.y > max.y ) max.y = newmax.y;
            if ( newmax.z > max.z ) max.z = newmax.z;
            
            it++;
        }
    }
    
    void addToCollisionCheck( TT_Custom_MSAParticle3D * _p )
    {
        colliders.push_back( _p );
    }
    
    void removeFromCollisionCheck( TT_Custom_MSAParticle3D * _p )
    {
        
    }
    
private:
    
    bool checkCollisionBetween( Physics::Particle3D * a, Physics::Particle3D * b )
    {
        
        if( a==b ) return false;
        if (a->isFixed()) return false;
        // only collide the ones which have collision enabled.
        if (a->hasCollision() == false ) return false;
        
        // check with bounding box
        Vec3f a_pos = a->getPosition();
        if (a_pos.x > max.x || a_pos.x < min.x  ) return false;
        if (a_pos.y > max.y || a_pos.y < min.y  ) return false;
        if (a_pos.z > max.z || a_pos.z < min.z  ) return false;
        
        
        if((a->collisionPlane & b->collisionPlane) == 0) {
            return false;
        }
        //        printf("same planes %i %i\n", a->collisionPlane, b->collisionPlane);
        
        float restLength = b->getRadius() + a->getRadius();
        Vec3f delta = b->getPosition() - a_pos;
        float deltaLength2 = delta.lengthSquared();
        if(deltaLength2 >restLength * restLength) return false;
        
        float deltaLength = sqrt(deltaLength2);	// TODO: fast approximation of square root (1st order Taylor-expansion at a neighborhood of the rest length r (one Newton-Raphson iteration with initial guess r))
        float force = (deltaLength - restLength) / (deltaLength * (a->getInvMass() + b->getInvMass()));
        
        Vec3f deltaForce = delta * force;
        
        if (a->isFree()) a->moveBy(deltaForce * a->getInvMass(), false);
        //        if (b->isFree()) b->moveBy(deltaForce * -b->getInvMass(), false);
        
        //        a->collidedWithParticle(b, deltaForce);
        //        b->collidedWithParticle(a, -deltaForce);
        
        return true;
    }
};

