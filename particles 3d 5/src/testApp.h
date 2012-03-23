#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxSimpleGuiToo.h"

#include "TT_DiscoBoxApp.h"
#include "TT_FogAnimated.h"
//#include "MSAParticleSystem3D.h"
//#include "MSAParticleSystem3D_Groups.h"
#include "MSAParticleSystemEvented.h"

//#include "MSAFluidManager.h"
#include "MSAFluidManagerApp.h"

//#include "MSAPhysicsFluidUpdater.h"
#include "MSAPhysicsFluidUpdater3D.h"
#include "MSAPhysicsUpdaterShake.h"

#include "TT_SoundPlayer.h"
#include "TT_SoundPlayer_gui.h"
#include "TT_SoundManager.h"

#include "TT_Presets.h"

#include "TT_Sequencer_Quiet.h"

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
    
    TT_DiscoBoxApp  box;
	ofEasyCam       camera;
    TT_FogAnimated  fog;
    
    void            buildScene();

    //---------------------------------------------- Particles
    
    MSAParticleSystemEvented ps;
    
    //---------------------------------------------- FLUID
    MSAFluidManagerApp          fluid;
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
    
    string              preset_path;
    
    //---------------------------------------------- Presets
    void        nextPreset();
    TT_Presets  my_presets;
    
    //---------------------------------------------- Sequencer    
    TT_Sequencer_Quiet    seq;
    
};

