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
    
    vel_new = solver->getVelocityAtPos( pos_old * invWindowSize ) * (_p->getMass() * fluid_force ) * windowSize + vel_old * momentum;
    
    vel3D_new = Vec3f( vel_new.x, vel_new.y, _p->getVelocity().z ); //Vec3f( vel_new.x, vel_new.y, _p->getVelocity().z );
    _p->setVelocity( vel3D_new );
    
}

//--------------------------------------------------------------------- SETTINGS
void MSAPhysicsFluidUpdater::addSettings( ofxSimpleGuiToo & _gui )
{
    _gui.addTitle( "Fluid Updater Settings").setNewColumn(true);
    _gui.addSlider( "Fluid Force", fluid_force, 0,1);
    _gui.addSlider( "Momentum", momentum, 0,1);
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
	invWindowSize = Vec2f( 1.0f / _windowSize.x, 1.0f );
}