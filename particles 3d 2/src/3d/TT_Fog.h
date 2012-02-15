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
    
public:
    
    ofFloatColor    color;
    
    TT_Fog()
    {
        color = ofFloatColor( 1,1,1,1 );
    }
    
    void draw()
    {
        GLfloat fogColor[4] = {color.r,color.g,color.b, color.a};
        
        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogfv(GL_FOG_COLOR, fogColor);
        glFogf(GL_FOG_DENSITY, 1);
        glHint(GL_FOG_HINT, GL_NICEST);
        glFogf(GL_FOG_START, start);
        glFogf(GL_FOG_END, end);
        glEnable(GL_FOG);
    }
    
    void defineStartAndEnd( int _start, int _end )
    {
        start   = _start;
        end     = _end;
    }
    
    void addSettings( ofxSimpleGuiToo & _gui )
    {
//        _gui.addColorPicker("Fog Color Red", &color.r);        
        _gui.addTitle( "Fog Colors" );
        _gui.addSlider( "Fog Red", color.r, 0,1);
        _gui.addSlider( "Fog Green", color.g, 0,1);
        _gui.addSlider( "Fog Blue", color.b, 0,1);
        _gui.addSlider( "Fog Alpha", color.a, 0,1);
    }
    
    
};