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
#include "MSATimer.h"
#include "baseforce.h"
#include "sinewaveforce.h"


class MSAFluidManager {

    FluidSolver         fluidsolver;
    FluidDrawerGl       fluidDrawer;
    
    int                 fluidCellsX;
    bool                drawFluid;
    bool                resizeFluid;
    int                 velocityMult;
    float               global_fluid_strength;
    float               fixedforce_power;
    Vec2f               pMouse;
    
    // ---------------------------------------------- FORCES
    
    vector<BaseForce*>  forces;
    Timer               fluid_timer;

public:
    
    void setup();
    void update();
    void draw();
    
	void addToFluid( Vec2f pos, Vec2f vel );
    void addRandomPosForce();
    
    // ---------------------------------------------- SETTINGS
    void addSettings( ofxSimpleGuiToo & _gui );
    ofxSimpleGuiPage *  gui_page;

};


#endif
