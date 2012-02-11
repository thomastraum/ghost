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
        classname = "BaseForce";
    };
    
    virtual void    setup( MSAFluidManager * manager );
    virtual void    update();
    virtual void    draw();
    
    void            enable( bool _is_enabled );
    bool            isEnabled();
    
    void            setTimer( Timer * _timer );
    void            setOrigin( Vec2f _origin );
    void            setStrength( float _strength );
    
    void            addToFluid( Vec2f origin, Vec2f vel );
    
    // ------------------------------------------------------- Settings
    void            addSettings( string _instance_name, ofxSimpleGuiToo & _gui );
    string const    getClassName() { return classname; }
    
    
protected:
    
    string  classname;
    
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