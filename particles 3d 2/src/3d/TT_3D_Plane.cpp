//
//  TT_3D_Plane.cpp
//  basic 3d scene 1
//
//  Created by Thomas Eberwein on 05/02/2012.
//  Copyright 2012 --. All rights reserved.
//

#include "TT_3D_Plane.h"

//--------------------------------------------------------------
void TT_3D_Plane::customDraw()
{
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    glPushMatrix();
    setScale(width,height,1);
    vbo.draw( GL_QUADS, 0, 4 );
    glPopMatrix();

    ofDisableAlphaBlending();
    glDisable(GL_DEPTH_TEST);
}

void TT_3D_Plane::toggleDebugDraw()
{
    
}


void TT_3D_Plane::keyPressed( ofKeyEventArgs&args )
{
//    if ( args.key == "d" ) {
//        color = ofColor( 
//    }
}