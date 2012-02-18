#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxSimpleGuiToo.h"

#include "TT_3D_Plane.h"
#include "TT_Fog.h"
//#include "MSAParticleSystem3D.h"
#include "MSAParticleSystem3D_tt.h"

#include "MSAFluidManager.h"
#include "MSAPhysicsFluidUpdater.h"
#include "MSAPhysicsUpdaterShake.h"

#include "TT_Presets.h"

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
    ofColor     plane_color;
    
	ofxGrabCam  camera;
    TT_Fog      fog;
    
    void        buildScene();

    //---------------------------------------------- Particles
    
    MSAParticleSystem3D_tt ps;
    
    //---------------------------------------------- FLUID
    MSAFluidManager         fluid;
    MSAPhysicsFluidUpdater  fluid_updater;
    
    MSAPhysicsUpdaterShake  shaker;
    
    //---------------------------------------------- Settings
    void addAppSettings();
    void loadXMLSettings();
    void loadXMLSettingsFromPath( string _path );
    
    void                addMainSettings();
    void                setXMLFilename( string _xml_filename );
    ofxSimpleGuiPage *  main_page;
    
    string preset_path;
    
    //--------------
    
    TT_Presets my_presets;
    
};

