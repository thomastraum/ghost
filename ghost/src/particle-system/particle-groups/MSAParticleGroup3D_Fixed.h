//
//  MSAParticleGroup3D_Fixed.h
//  ghost
//
//  Created by Thomas Eberwein on 27/04/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "MSAParticleGroup3D.h"

class MSAParticleGroup3D_Fixed : public MSAParticleGroup3D {
    
public:
    
    MSAParticleGroup3D_Fixed() {
    }
    
    virtual void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3D::setParticleProperties( _p );
        float radius	= ofMap( _p->getMass(), mass_min, mass_max, node_min, node_max );
        _p->setRadius( radius );
        _p->makeFixed();
    }

    
    //--------------------------------------------------------------- SETTINGS
    void addSettings( ofxSimpleGuiToo & _gui )
    {
        MSAParticleGroup3D::addSettings( _gui );
        _gui.addSlider( instance_name + "node min", node_min, 1, 200);
        _gui.addSlider( instance_name + "node max", node_max, 1, 600);
    }
    
};