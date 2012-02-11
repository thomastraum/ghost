//
//  TT_3D_Plane.h
//  basic 3d scene 1
//
//  Created by Thomas Eberwein on 05/02/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef basic_3d_scene_1_TT_3D_Plane_h
#define basic_3d_scene_1_TT_3D_Plane_h

#pragma once
#include "ofMain.h"

#define HEIGHT  100
#define WIDTH   100

class TT_3D_Plane : public ofNode {
    
    ofMesh  mesh;
    ofVbo   vbo;
    
public:
    
    TT_3D_Plane(){
        
        width   = WIDTH;
        height  = HEIGHT;
        
        // plane 1
        mesh.addVertex( ofVec3f( -1,-1,0) );
        mesh.addVertex( ofVec3f( 1,-1,0) );
        mesh.addVertex( ofVec3f( 1,1,0) );
        mesh.addVertex( ofVec3f( -1,1,0) );
        
        mesh.addColor(ofFloatColor(1,0,0,1));
        mesh.addColor(ofFloatColor(1,1,0,1));
        mesh.addColor(ofFloatColor(0,1,0,1));
        mesh.addColor(ofFloatColor(0,1,1,1));
        
        vbo.setMesh( mesh,GL_STATIC_DRAW );
        
        ofAddListener(ofEvents.keyPressed, this, &TT_3D_Plane::keyPressed );
    }
    
    int width;
    int height;
    
    void customDraw();
    
    void toggleDebugDraw();
    void keyPressed( ofKeyEventArgs&args );
    
};




#endif
