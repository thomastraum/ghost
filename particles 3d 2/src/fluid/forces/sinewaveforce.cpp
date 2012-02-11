//
//  sinewaveforce.cpp
//  body-impact-1
//
//  Created by Thomas Eberwein on 07/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#include "sinewaveforce.h"

void SineWaveForce::update()
{
    int max = ofRandom( 5, 20 );
    float step = 1.0f / max;
    
    Vec2f pos = origin;
    
    for (int i=0; i<max; i++) {
        pos.y += step;
        vel.x = sin(pos.y * (PI/2) - (offset*PI/2) ) * sin(fmod(timer->getSeconds()*freq, TWO_PI)) * strength;
        addToFluid( pos, vel );
    }
}

void SineWaveForce::draw()
{
    
}

void SineWaveForce::addSettings( string _instancename, ofxSimpleGuiToo & _gui)
{
    BaseForce::addSettings( _instancename, _gui );
    _gui.addSlider( _instancename + " Freq", freq, 0.1, 5 ).setSmoothing(slider_smoothing);
    _gui.addSlider( _instancename + " Offset", offset, 0, 1 ).setSmoothing(slider_smoothing);
    freq = 2;
    offset = 1;
}
