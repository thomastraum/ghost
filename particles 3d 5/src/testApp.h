#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxSimpleGuiToo.h"

#include "TT_DiscoBox.h"
#include "TT_Fog.h"
//#include "MSAParticleSystem3D.h"
#include "MSAParticleSystem3D_tt.h"

#include "MSAFluidManager.h"
//#include "MSAPhysicsFluidUpdater.h"
#include "MSAPhysicsFluidUpdater3D.h"
#include "MSAPhysicsUpdaterShake.h"

#include "TT_SoundPlayer.h"
#include "TT_SoundPlayer_gui.h"
#include "TT_SoundManager.h"

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
    
    TT_DiscoBox box;
    
	ofEasyCam   camera;
    TT_Fog      fog;
    
    void        buildScene();

    //---------------------------------------------- Particles
    
    MSAParticleSystem3D_tt ps;
    
    //---------------------------------------------- FLUID
    MSAFluidManager             fluid;
    MSAPhysicsFluidUpdater3D    fluid_updater;
    MSAPhysicsUpdaterShake      shaker;
    
    //---------------------------------------------- SOUND MANAGER
    TT_SoundManager             sm;
    
    
    //---------------------------------------------- Settings
    void addAppSettings();
    void loadXMLSettings();
    void loadXMLSettingsFromPath( string _path );
    
    void                addMainSettings();
    void                setXMLFilename( string _xml_filename );
    ofxSimpleGuiPage *  main_page;
    
    string preset_path;
    
    //---------------------------------------------- Presets
    void        nextPreset();
    TT_Presets  my_presets;
    
};

