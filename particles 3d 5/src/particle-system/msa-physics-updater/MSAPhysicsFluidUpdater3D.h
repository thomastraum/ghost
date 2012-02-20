//
//  MSAPhysicsFluidUpdater3D.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 19/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "MSAPhysicsFluidUpdater.h"

class MSAPhysicsFluidUpdater3D : public MSAPhysicsFluidUpdater {
    
    float   angle;
    float   rad;
    Vec3f   vel3d_new;
    
public:
    
    MSAPhysicsFluidUpdater3D() {
        angle = 90;
        rad = ofDegToRad( angle );
    }
    
    void update(Physics::Particle3D *_p)
    {
        pos_old.x = _p->getPosition().x + windowSize.x/2;
        pos_old.y = _p->getPosition().y + windowSize.y/2;
        
        vel_old.x = _p->getVelocity().x;
        vel_old.y = _p->getVelocity().y;
        
        // original solver equation
        // vel = solver.getVelocityAtPos( pos * invWindowSize ) * (mass * fluid_influence ) * windowSize + vel * MOMENTUM;
        vel_new = solver->getVelocityAtPos( pos_old * invWindowSize ) * (_p->getMass() * fluid_influence ) * windowSize + vel_old * momentum;
        
        
        vel3D_new.x = sin(rad) * _p->getVelocity().z  - cos(rad)*vel_new.x;
        vel3D_new.y = vel_new.y;
        vel3D_new.z = cos(rad)*_p->getVelocity().z + sin(rad)*vel_new.x;
        
//        vel3D_new = Vec3f( vel_new.x, vel_new.y, vel_new.z ); //Vec3f( vel_new.x, vel_new.y, _p->getVelocity().z );
        
        _p->addVelocity(vel3D_new);
    }
};


/*

 
 x' = z*sin q + x*cos q
 y' = y
 z' = z*cos q - x*sin q
 
 
 # 2 points on a plane
 my $x = 2;
 my $y = 1;
 #yang is the y-angle 0-360 i want to rotate by
 my $yang = 45;
 #convert yang to radians
 $yang = 3.14159265358979*$yang/180;
 my $xnew = cos($yang)*$x - sin($yang)*y;
 my $ynew = sin($yang)*$x + cos($yang)*y;
 print "x=$xnew, y=$ynew\n";

*/