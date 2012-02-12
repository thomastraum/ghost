//
//  msaPhysicsUpdater.cpp
//  body-impact-1
//
//  Created by Thomas Eberwein on 02/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#include "MSAPhysicsFluidUpdater.h"

void MSAPhysicsFluidUpdater::setup(const MSA::FluidSolver * _solver)
{
    solver = _solver;
    momentum = .2f;
    fluid_force = 0.6f;
    
    MSAPhysicsUpdater3D::setWindowSize( Vec2f( ofGetWidth(), ofGetHeight() ) );
}

void MSAPhysicsFluidUpdater::update(Physics::Particle3D *_p)
{
    pos_old = Vec2f(_p->getPosition().x, _p->getPosition().y );
    vel_old = Vec2f( _p->getVelocity().x, _p->getVelocity().y );
    
    vel_new = solver->getVelocityAtPos( pos_old * invWindowSize ) * (_p->getMass() * fluid_force ) * windowSize + vel_old * momentum;
    
    vel3D_new = Vec3f( vel_new.x, vel_new.y, _p->getVelocity().z ); //Vec3f( vel_new.x, vel_new.y, _p->getVelocity().z );
    _p->setVelocity( vel3D_new );
    
}

void MSAPhysicsFluidUpdater::addSettings( ofxSimpleGuiToo & _gui )
{
    _gui.addTitle( "Fluid Updater Settings").setNewColumn(true);
    _gui.addSlider( "Fluid Force", fluid_force, 0,1);
    _gui.addSlider( "Momentum", momentum, 0,1);
}