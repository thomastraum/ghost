//
//  TT_Box.cpp
//  particles 3d 5
//
//  Created by Thomas Eberwein on 19/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "TT_Box.h"


void TT_Box::build()
{
    bottom.setPosition(0, -1, 0);
    bottom.setOrientation(ofVec3f(90,0,0));
    
    left.setPosition(-1, 0, 0);
    left.setOrientation(ofVec3f(0,90,0));
    
    top.setPosition(0, 1, 0);
    top.setOrientation(ofVec3f(90,0,0));
    
    right.setPosition(1, 0, 0);
    right.setOrientation(ofVec3f(0,90,0));
    
    back.setPosition(0, 0, -1);
}


void TT_Box::customDraw()
{
    drawBox();
}

void TT_Box::drawBox()
{
//    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    glPushMatrix();
    setScale(width,height,height);
    
    bottom.draw();
    left.draw();
    top.draw();
    right.draw();
    back.draw();
    
    glPopMatrix();
    
//    ofDisableAlphaBlending();
    glDisable(GL_DEPTH_TEST);
}

void TT_Box::setColor( ofFloatColor _c )
{
    c = _c;
    bottom.setColor( _c );
    left.setColor( _c );
    top.setColor( _c );
    right.setColor( _c );
    back.setColor( _c );
}

ofFloatColor TT_Box::getColor()
{
    return c;
}