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
    
    float steps;
    
public:
    
    ForceFromSide(){
        classname = "ForceFromSide";
        steps = 10;
    };
    
    void update()
    {
        if (is_enabled ) {
            float step = 1 / steps;

            for (int i=0; i<steps; i++) {
                addToFluid( Vec2f(origin.x, step*i), Vec2f(strength, 0) );
            }
        }
    }
    
    void addSettings( string _instance_name, ofxSimpleGuiToo &_gui)
    {
        BaseForce::addSettings( _instance_name, _gui );
        _gui.addSlider( "Steps", steps, 0, 40 ).setSmoothing(slider_smoothing);
    }
    
};