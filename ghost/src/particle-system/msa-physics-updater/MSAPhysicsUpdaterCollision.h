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
    
    vector<TT_Custom_MSAParticle3D * > * colliders;
    
private:
    
    bool checkCollisionBetween( TT_Custom_MSAParticle3D * a, TT_Custom_MSAParticle3D * b )
    {
        return true;
    }
    
public:
    
    MSAPhysicsUpdaterCollision(){};
    
    virtual void update( Physics::Particle3D * _p )
    {
        
    }
    
    void checkCollisionWithThese( vector<TT_Custom_MSAParticle3D * > * _colliders )
    {
        colliders = _colliders;
    }
};


/*

 bool SectorT<T>::checkCollisionBetween(ParticleT<T> *a, ParticleT<T> *b) {
 if(a->hasCollision() == false || b->hasCollision() == false) return false;
 
 if((a->collisionPlane & b->collisionPlane) == 0) {
 return false;
 }
 //			printf("same planes %i %i\n", a->collisionPlane, b->collisionPlane);
 
 float restLength = b->getRadius() + a->getRadius();
 T delta = b->getPosition() - a->getPosition();
 float deltaLength2 = delta.lengthSquared();
 if(deltaLength2 >restLength * restLength) return false;
 
 float deltaLength = sqrt(deltaLength2);	// TODO: fast approximation of square root (1st order Taylor-expansion at a neighborhood of the rest length r (one Newton-Raphson iteration with initial guess r))
 float force = (deltaLength - restLength) / (deltaLength * (a->getInvMass() + b->getInvMass()));
 
 T deltaForce = delta * force;
 
 if (a->isFree()) a->moveBy(deltaForce * a->getInvMass(), false);
 if (b->isFree()) b->moveBy(deltaForce * -b->getInvMass(), false);
 
 a->collidedWithParticle(b, deltaForce);
 b->collidedWithParticle(a, -deltaForce);
 
 return true;
 }

*/