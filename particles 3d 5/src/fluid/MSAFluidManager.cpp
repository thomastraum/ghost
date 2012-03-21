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
    velocityMult        = 30;
    
	draw_fluid			= false;
    resize_fluid        = false;
    
    // Sine setup 1
    BaseForce * force = new SineWaveForce();
    force->setup( this );
    force->setInstanceName( "Sine 1" );
    force->setOrigin( Vec2f( 0, 0 ) );
    forces.push_back( force );
    
    // Sine setup 1
    force = new SineWaveForce();
    force->setup( this );
    force->setInstanceName( "Sine 2" );
    force->setOrigin( Vec2f( 1, 1 ) );
    forces.push_back( force );
    
    // force from left side //
    force = new ForceFromSide();
    force->setup( this );
    force->setInstanceName( "Side 1" );
    force->setOrigin( Vec2f(0,0) );
    forces.push_back( force );
    
    // force from left side //
    force = new ForceFromSide();
    force->setup( this );
    force->setInstanceName( "Side 2" );
    force->setOrigin( Vec2f(1,0) );
    forces.push_back( force );
    
    fixedforce_power    = 0.006;
}

//--------------------------------------------------------------------------
void MSAFluidManager::update()
{
    if(resize_fluid) 	{
		fluidsolver.setSize(fluidCellsX, fluidCellsX / getWindowAspectRatio() );
		fluidDrawer.setup(&fluidsolver);
		resize_fluid = false;
	}
    
    for ( int i=0;i<forces.size(); i++ ) {
        forces[i]->update();
    }
    
	fluidsolver.update();
}

//--------------------------------------------------------------------------
void MSAFluidManager::draw()
{
    if (draw_fluid) {
        ofColor(255,255,255);
        fluidDrawer.draw(0, 0, getWindowWidth(), getWindowHeight());
    }
}

//-------------------------------------------------------------------------- HELPERS
// Add force and dye to fluid
// takes normalized pos for Fluid //
void MSAFluidManager::addToFluid( Vec2f pos, Vec2f vel) 
{
    // balance the x and y components of speed with the screen aspect ratio
    float speed = vel.x * vel.x  + vel.y * vel.y * getWindowAspectRatio() * getWindowAspectRatio();
    
    if(speed > 0) {
        
        pos.x = constrain(pos.x, 0.0f, 1.0f);
        pos.y = constrain(pos.y, 0.0f, 1.0f);
        
//        const float colorMult = 100;
        
        int index = fluidsolver.getIndexForPos(pos);
        
        fluidsolver.addForceAtIndex(index, vel * velocityMult );
    }
		
}

//-------------------------------------------------------------------------- 
FluidSolver * MSAFluidManager::getSolver()
{
    return &fluidsolver;
}

//-------------------------------------------------------------------------- SETTINGS
void MSAFluidManager::addSettings( ofxSimpleGuiToo & _gui )
{
    gui_page = & _gui.addPage("MSAFluidManager");
    
    _gui.addSlider("fluidCellsX", fluidCellsX, 20, 400);
	_gui.addButton("resize_fluid", resize_fluid);
	_gui.addSlider("fs.viscocity", fluidsolver.viscocity, 0.0, 0.001); 
	_gui.addSlider("fs.colorDiffusion", fluidsolver.colorDiffusion, 0.0, 0.0003); 
	_gui.addSlider("fs.fadeSpeed", fluidsolver.fadeSpeed, 0.0, 0.1); 
	_gui.addSlider("fs.solverIterations", fluidsolver.solverIterations, 1, 50); 
	_gui.addSlider("fs.deltaT", fluidsolver.deltaT, 0.1, 5);
    _gui.addComboBox("fd.drawMode", (int&)fluidDrawer.drawMode, kFluidDrawCount, (string*)FluidDrawerGl::drawOptionTitles);
	_gui.addToggle("fs.doRGB", fluidsolver.doRGB); 
	_gui.addToggle("fs.doVorticityConfinement", fluidsolver.doVorticityConfinement); 
	_gui.addToggle("draw_fluid", draw_fluid);
	_gui.addToggle("fs.wrapX", fluidsolver.wrap_x);
	_gui.addToggle("fs.wrapY", fluidsolver.wrap_y);
    
    _gui.addSlider( "Fluid Strength", fixedforce_power, 0, 0.1);
    
    for ( int i=0;i<forces.size(); i++ ) {
        forces[i]->addSettings( _gui);
    }
}

void MSAFluidManager::setXMLFilename( string _name )
{
//    xml_filename = _xml_filename;
    gui_page->setXMLName( _name );
}







