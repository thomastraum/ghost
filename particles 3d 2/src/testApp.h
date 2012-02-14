#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxSimpleGuiToo.h"

#include "TT_3D_Plane.h"
#include "MSAParticleSystem3D.h"

#include "MSAFluidManager.h"
#include "MSAPhysicsFluidUpdater.h"
#include "MSAPhysicsUpdaterShake.h"

class testApp : public ofBaseApp{

public:
    
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void windowResized(int w, int h);
    
    ofxSimpleGuiToo gui;
    
private:    
    
    bool    draw_debug;
    
    int     width;
    int     height;
    
    TT_3D_Plane plane_bottom;
    TT_3D_Plane plane_left;
    TT_3D_Plane plane_top;
    TT_3D_Plane plane_right;
    TT_3D_Plane plane_back;
    
	ofxGrabCam  camera;
    
    void        buildScene();

    //---------------------------------------------- Particles
    
    MSAParticleSystem3D ps;
    
    //---------------------------------------------- FLUID
    MSAFluidManager         fluid;
    MSAPhysicsFluidUpdater  fluid_updater;
    
    MSAPhysicsUpdaterShake  shaker;
    
    //---------------------------------------------- Settings
    void addAppSettings();
    void loadXMLSettings();
    
    
    
};
