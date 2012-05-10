//
//  MSAPhysicsUpdaterCollision.h
//  ghost
//
//  Created by Thomas Eberwein on 27/04/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "MSAPhysics3D.h"

using namespace MSA;

class MSAPhysicsUpdaterCollision : public Physics::ParticleUpdater3D {
    
    vector<Physics::Particle3D * > colliders;
    
private:
    
    bool checkCollisionBetween( Physics::Particle3D * a, Physics::Particle3D * b )
    {
//        if(a->hasCollision() == false || b->hasCollision() == false) return false;
        
        if((a->collisionPlane & b->collisionPlane) == 0) {
            return false;
        }
//        printf("same planes %i %i\n", a->collisionPlane, b->collisionPlane);
        
        float restLength = b->getRadius() + a->getRadius();
        Vec3f delta = b->getPosition() - a->getPosition();
        float deltaLength2 = delta.lengthSquared();
        if(deltaLength2 >restLength * restLength) return false;
        
        float deltaLength = sqrt(deltaLength2);	// TODO: fast approximation of square root (1st order Taylor-expansion at a neighborhood of the rest length r (one Newton-Raphson iteration with initial guess r))
        float force = (deltaLength - restLength) / (deltaLength * (a->getInvMass() + b->getInvMass()));
        
        Vec3f deltaForce = delta * force;
        
        if (a->isFree()) a->moveBy(deltaForce * a->getInvMass(), false);
        if (b->isFree()) b->moveBy(deltaForce * -b->getInvMass(), false);
        
//        ofLogNotice("TT") << delta;
//        ofLogNotice("TT") << force;
//        ofLogNotice("TT") << deltaForce;
        
        a->collidedWithParticle(b, deltaForce);
        b->collidedWithParticle(a, -deltaForce);
        
        return true;
        
//        return false;
    }
    
public:
    
    MSAPhysicsUpdaterCollision(){};
    
    virtual void update( Physics::Particle3D * _pA )
    {
        vector<Physics::Particle3D*>::iterator it = colliders.begin();
        
        while( it != colliders.end() ) {
            
            Physics::Particle3D * pB = *it;
            if ( checkCollisionBetween( _pA, pB ) ) {
                _pA->kill();
//                pB->kill();
                break;
            }
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
    
    void checkCollisionWithThese( vector<TT_Custom_MSAParticle3D * > * _colliders )
    {
//        colliders = _colliders;
    }
};

