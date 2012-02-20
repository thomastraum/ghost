//
//  TT_Box.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 19/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "TT_3D_Plane.h"

#define WIDTH 1
#define HEIGHT 1


class TT_Box : public ofNode {
    
    TT_3D_Plane                 top, right, bottom, left, back;
    
public:
    
    TT_Box() {
        
        width = WIDTH;
        height = HEIGHT;
    }
    
    int width;
    int height;
    
    void build();
    virtual void customDraw();
    void drawBox();
    
    void setColor( ofFloatColor color );
    
};