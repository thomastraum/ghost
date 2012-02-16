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
    
    float   steps;
    int     steps_min;
    int     steps_max;
    int     dir;
    
    bool left_right;
    
public:
    
    ForceFromSide(){
        classname = "ForceFromSide";
        steps_min = 5;
        steps_max = 15;
        
        dir = 1;
        left_right = false;
    };
    
    void update()
    {
        if (is_enabled ) {
            steps = ofRandom( steps_min, steps_max );
            float step = 1.0 / steps;
            dir = (left_right==true) ? 1 : -1; 
            for (int i=0; i<steps; i++) {
                addToFluid( Vec2f(origin.x, step*i), Vec2f(strength*dir, 0) );
            }
        }
    }
    
    void addSettings( string _instance_name, ofxSimpleGuiToo &_gui)
    {
        BaseForce::addSettings( _instance_name, _gui );
        _gui.addSlider( "Steps Min", steps_min, 0, 40 ).setSmoothing(slider_smoothing);
        _gui.addSlider( "Steps Max", steps_max, 0, 40 ).setSmoothing(slider_smoothing);
        _gui.addToggle( "Direction", left_right );
    }
    
};