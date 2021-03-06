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
    momentum = .5f;
    fluid_influence = 0.6f;
    
	setWindowSize( Vec2f( ofGetWidth(), ofGetHeight() ) );
    ofAddListener(ofEvents.windowResized, this, &MSAPhysicsFluidUpdater::windowResized);
}

//--------------------------------------------------------------------- Update
void MSAPhysicsFluidUpdater::update(Physics::Particle3D *_p)
{
    pos_old.x = _p->getPosition().x + windowSize.x/2;
	pos_old.y = _p->getPosition().y + windowSize.y/2;
    
    vel_old.x = _p->getVelocity().x;
	vel_old.y = _p->getVelocity().y;
    
    // original solver equation
    // vel = solver.getVelocityAtPos( pos * invWindowSize ) * (mass * fluid_influence ) * windowSize + vel * MOMENTUM;
    vel_new = solver->getVelocityAtPos( pos_old * invWindowSize ) * (_p->getMass() * fluid_influence ) * windowSize + vel_old * momentum;
    
    vel3D_new = Vec3f( vel_new.x, vel_new.y, 0 ); //Vec3f( vel_new.x, vel_new.y, _p->getVelocity().z );
    _p->addVelocity(vel3D_new);    
}

//--------------------------------------------------------------------- Resize
void MSAPhysicsFluidUpdater::windowResized(ofResizeEventArgs&args )
{	
	setWindowSize( Vec2f( args.width, args.height ) );
}

//--------------------------------------------------------------------- 
void MSAPhysicsFluidUpdater::setWindowSize( Vec2f _windowSize ) 
{
    windowSize = _windowSize;
	invWindowSize = Vec2f( 1.0f / _windowSize.x, 1.0f / _windowSize.y );
}

//--------------------------------------------------------------------- SETTINGS
void MSAPhysicsFluidUpdater::addSettings( ofxSimpleGuiToo & _gui )
{
    _gui.addTitle( "Fluid Updater Settings"); //.setNewColumn(true);
    _gui.addSlider( "Fluid Influence", fluid_influence, 0,.25);
    _gui.addSlider( "Momentum", momentum, 0,.25);
}