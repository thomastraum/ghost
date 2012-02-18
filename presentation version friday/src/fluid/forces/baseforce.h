//
//  baseforce.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 07/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once

#include "MSACore.h"
#include "MSATimer.h"
#include "ofxSimpleGuiToo.h"

//#include "MSAFluidManager.h"

using namespace MSA;

class MSAFluidManager;

class BaseForce {

public:
    
    BaseForce(){
        instance_name = "Name Not Set!";
    };
    
    virtual void    setup( MSAFluidManager * manager );
    virtual void    update();
    virtual void    draw();
    
    void            enable( bool _is_enabled );
    bool            isEnabled();
    
    void            setOrigin( Vec2f _origin );
    void            setStrength( float _strength );
    
    void            addToFluid( Vec2f origin, Vec2f vel );
    
    // ------------------------------------------------------- Settings
    virtual void    addSettings( ofxSimpleGuiToo & _gui );
    void            setInstanceName( string _instance_name )
    {
        instance_name = _instance_name;
    };
    
    
protected:
    
    string  instance_name;
    
    MSAFluidManager *   manager;
    Timer *             timer;
    
    bool    is_enabled;
    
    Vec2f   origin;
    Vec2f   vel;
    float   strength;
    
    bool    add_particles;
    bool    add_fluid;
    
    float   slider_smoothing;
    
};