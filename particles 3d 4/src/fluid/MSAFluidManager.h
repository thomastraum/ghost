//
//  MSAFluidManager.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 10/02/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_2_MSAFluidManager_h
#define particles_3d_2_MSAFluidManager_h

#pragma once
#include "MSAFluid.h"
#include "baseforce.h"
#include "sinewaveforce.h"
#include "ForceFromSide.h"

class MSAFluidManager {

private:
    
    FluidSolver         fluidsolver;
    FluidDrawerGl       fluidDrawer;
    
    int                 fluidCellsX;
    int                 velocityMult;

    bool                draw_fluid;
    bool                resize_fluid;
    
    float               fixedforce_power;
    Vec2f               pMouse;
    
    // ---------------------------------------------- FORCES
    vector<BaseForce*>  forces;

public:
    
    void setup();
    void update();
    void draw();
    
	void addToFluid( Vec2f pos, Vec2f vel );
    
    void addRandomPosForce();
    
    FluidSolver * getSolver();
    
    // ---------------------------------------------- SETTINGS
    void addSettings( ofxSimpleGuiToo & _gui );
    void setXMLFilename( string _name );
    ofxSimpleGuiPage *  gui_page;

};


#endif
