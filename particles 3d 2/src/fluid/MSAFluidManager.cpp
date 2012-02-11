//
//  MSAFluidManager.cpp
//  particles 3d 2
//
//  Created by Thomas Eberwein on 10/02/2012.
//  Copyright 2012 --. All rights reserved.
//

#include "MSAFluidManager.h"

void MSAFluidManager::setup()
{
    // Fluid
	fluidsolver.setup(50, 50);
    fluidsolver.enableRGB(false).setFadeSpeed(0.002).setDeltaT(.5).setVisc(0.00050).setColorDiffusion(0).enableVorticityConfinement(false).setWrap(false,false).setSolverIterations(40);
    
	fluidDrawer.setup( &fluidsolver );
	fluidCellsX			= 70;
	drawFluid			= false;
    velocityMult        = 30;
    global_fluid_strength = 1.0;
    
    // Sine setup 1
    BaseForce * force = new SineWaveForce();
    force->setup( this );
    force->setTimer( &fluid_timer );
    force->setOrigin( Vec2f( 0, 0 ) );
    forces.push_back( force );
    
    fixedforce_power    = 0.006;
}

//--------------------------------------------------------------------------
void MSAFluidManager::update()
{
	fluidsolver.update();
    
    for ( int i=0;i<forces.size(); i++ ) {
        forces[i]->update();
    }
}

//-------------------------------------------------------------------------- HELPERS
// Add force and dye to fluid, and create particles
// takes normalized pos for Fluid //
void MSAFluidManager::addToFluid( Vec2f pos, Vec2f vel) 
{
    // balance the x and y components of speed with the screen aspect ratio
    float speed = vel.x * vel.x  + vel.y * vel.y * getWindowAspectRatio() * getWindowAspectRatio();
    
    if(speed > 0) {
        
        pos.x = constrain(pos.x, 0.0f, 1.0f);
        pos.y = constrain(pos.y, 0.0f, 1.0f);
        
        const float colorMult = 100;
        
        int index = fluidsolver.getIndexForPos(pos);
        fluidsolver.addForceAtIndex(index, vel * velocityMult * global_fluid_strength);
    }
		
}

void MSAFluidManager::addRandomPosForce()
{
    Vec2f pos = Vec2f( Rand::randFloat( 0,1), Rand::randFloat(0,1) );
    Vec2f vel = Vec2f( Rand::randVec2f() ) * fixedforce_power;
    //    Vec2f vel = Vec2f( Rand::randFloat( 0,1), Rand::randFloat(0,1) ) * fixedforce_power;
    addToFluid( pos, vel );
}

void MSAFluidManager::addSettings( ofxSimpleGuiToo & _gui )
{
    gui_page = & _gui.addPage("MSAFluidManager");
    
    _gui.addSlider("fluidCellsX", fluidCellsX, 20, 400);
	_gui.addButton("resizeFluid", resizeFluid);
	_gui.addSlider("fs.viscocity", fluidsolver.viscocity, 0.0, 0.001); 
	_gui.addSlider("fs.colorDiffusion", fluidsolver.colorDiffusion, 0.0, 0.0003); 
	_gui.addSlider("fs.fadeSpeed", fluidsolver.fadeSpeed, 0.0, 0.1); 
	_gui.addSlider("fs.solverIterations", fluidsolver.solverIterations, 1, 50); 
	_gui.addSlider("fs.deltaT", fluidsolver.deltaT, 0.1, 5);
    _gui.addComboBox("fd.drawMode", (int&)fluidDrawer.drawMode, kFluidDrawCount, (string*)FluidDrawerGl::drawOptionTitles);
	_gui.addToggle("fs.doRGB", fluidsolver.doRGB); 
	_gui.addToggle("fs.doVorticityConfinement", fluidsolver.doVorticityConfinement); 
	_gui.addToggle("drawFluid", drawFluid);
	_gui.addToggle("fs.wrapX", fluidsolver.wrap_x);
	_gui.addToggle("fs.wrapY", fluidsolver.wrap_y);
    
    _gui.addSlider( "Force Multiplier", fixedforce_power, 0, 0.1);
    
    for ( int i=0;i<forces.size(); i++ ) {
        forces[i]->addSettings( "force", _gui);
    }

    
}
