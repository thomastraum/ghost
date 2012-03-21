//
//  baseforce.cpp
//  body-impact-1
//
//  Created by Thomas Eberwein on 07/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#include "baseforce.h"
#include "MSAFluidManager.h" // resolve

void BaseForce::setup( MSAFluidManager * _manager )
{
    manager = _manager;
    
    strength = .016;
    
    origin = Vec2f(0,0);
    vel = Vec2f(0,0);

    is_enabled      = false;
    add_particles   = true;
    add_fluid       = true;

    slider_smoothing = 0.1;
}

bool BaseForce::isEnabled( )
{
    return is_enabled;
}

void  BaseForce::enable( bool _is_enabled )
{
    is_enabled = _is_enabled;
}

void BaseForce::setOrigin( Vec2f _origin )
{
    origin = _origin;
}

void BaseForce::setStrength(float _strength)
{
    strength = _strength;
}

void BaseForce::addToFluid( Vec2f _origin, Vec2f _vel )
{
    manager->addToFluid( _origin, _vel );
}


void BaseForce::addSettings( ofxSimpleGuiToo & _gui )
{
    _gui.addTitle( instance_name ).setNewColumn(true);
	_gui.addSlider( instance_name + " Strength", strength, -.1, 0.1).setSmoothing(slider_smoothing);
    _gui.addToggle( instance_name + " Enabled", is_enabled );
}
