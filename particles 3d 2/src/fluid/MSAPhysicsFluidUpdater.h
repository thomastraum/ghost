//
//  msaPhysicsUpdater.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 02/06/2011.
//  Copyright 2011 --. All rights reserved.
//


#pragma once
#include "MSAPhysicsUpdater3D.h"
#include "MSAFluidSolver.h"
#include "ofxSimpleGuiToo.h"

using namespace MSA;

class MSAPhysicsFluidUpdater : public MSAPhysicsUpdater3D {
    
    Vec2f   pos_old;
    Vec2f   vel_new, vel_old;
    Vec3f   vel3D_new;
    
    float   momentum;
    float   fluid_force;
    float   max_spring_speed;
    
public:
    
    const FluidSolver * solver;
    
    void setup( const FluidSolver * _solver );
    void update( Physics::Particle3D * _p );
    
    void addSettings( ofxSimpleGuiToo & _gui );

};