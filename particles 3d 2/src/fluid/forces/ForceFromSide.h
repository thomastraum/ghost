//
//  ForceFromSide.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 14/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "baseforce.h"

class ForceFromSide : public BaseForce {
    
    float     steps;
    int     steps_min;
    int     steps_max;
    
public:
    
    ForceFromSide(){
        classname = "ForceFromSide";
        steps_min = 5;
        steps_max = 15;
    };
    
    void update()
    {
        if (is_enabled ) {
            steps = ofRandom( steps_min, steps_max );
            float step = 1.0 / steps;

            for (int i=0; i<steps; i++) {
                addToFluid( Vec2f(origin.x, step*i), Vec2f(strength, 0) );
            }
        }
    }
    
    void addSettings( string _instance_name, ofxSimpleGuiToo &_gui)
    {
        BaseForce::addSettings( _instance_name, _gui );
//        _gui.addSlider( "Steps", steps, 0, 40 ).setSmoothing(slider_smoothing);
    }
    
};