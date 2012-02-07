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
    glPushMatrix();
    setScale(width,height,1);
    vbo.draw( GL_QUADS, 0, 4 );
    glPopMatrix();
}