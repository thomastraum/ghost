//
//  TT_Fog.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 15/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class TT_Fog  {
        
//    GLfloat         fogColor[4];
    
    int start;
    int end;
    
    float   gui_smoothing;
    float   density;
    
public:
    
    ofFloatColor    color;
    
    
    TT_Fog()
    {
        // color is defined in presets //
        color = ofFloatColor( 1,1,1,1 );
        gui_smoothing = .5;
        start = 0;
        density = 1;
    }
    
    void draw()
    {
        GLfloat fogColor[4] = {color.r,color.g,color.b, color.a};
        
        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogfv(GL_FOG_COLOR, fogColor);
        glFogf(GL_FOG_DENSITY, density);
        glHint(GL_FOG_HINT, GL_DONT_CARE);
        glFogf(GL_FOG_START, start);
        glFogf(GL_FOG_END, end);
        glEnable(GL_FOG);
    }
    
    void setColor( ofFloatColor _c ) { color = _c; }
    ofFloatColor getColor() { return color; };
    
    void defineStartAndEnd( int _start, int _end )
    {
        start   = _start;
        end     = _end;
    }
    
    void addSettings( ofxSimpleGuiToo & _gui )
    {
//        _gui.addColorPicker("Fog Color Red", &color.r);        
        _gui.addTitle( "Fog Colors" );
        _gui.addSlider( "Fog Red", color.r, 0,1).setSmoothing( gui_smoothing );
        _gui.addSlider( "Fog Green", color.g, 0,1).setSmoothing( gui_smoothing );
        _gui.addSlider( "Fog Blue", color.b, 0,1).setSmoothing( gui_smoothing );
        _gui.addSlider( "Fog Alpha", color.a, 0,1).setSmoothing( gui_smoothing );
        
        _gui.addSlider( "Fog End", end, 0,10000).setSmoothing( gui_smoothing );
        _gui.addSlider( "Fog Start", start, -1000,4500).setSmoothing( gui_smoothing );
//        _gui.addSlider( "Fog Alpha", density, 0,1).setSmoothing( gui_smoothing );
    }
    
};