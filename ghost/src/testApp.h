#pragma once

#include "ofMain.h"
//#include "ofxGrabCam.h"
#include "ofxSimpleGuiToo.h"

//------------------------------------------------ 3D
#include "TT_DiscoBoxApp.h"
#include "TT_FogAnimated.h"
#include "TT_CamTargetAnimated.h"

//#include "MSAParticleSystem3D.h"
//#include "MSAParticleSystem3D_Groups.h"
#include "MSAParticleSystemEvented.h"

//#include "MSAFluidManager.h"
#include "MSAFluidManagerApp.h"

//#include "MSAPhysicsFluidUpdater.h"
#include "MSAPhysicsFluidUpdater3D.h"
#include "MSAPhysicsUpdaterShake.h"

//------------------------------------------------ SOUND
#include "TT_SoundPlayer.h"
#include "TT_SoundPlayer_gui.h"
#include "TT_SoundManager.h"

#include "TT_Presets.h"
#include "TT_Sequencer_Quiet.h"


//------------------------------------------------ OFXOPENNI
#include "TT_Player.h"
#include "TT_UserManager.h"
#include "MSAPhysicsUpdaterCollision.h"

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
    
    //---------------------------------------------- 3D
    
    TT_DiscoBoxApp          box;
	ofEasyCam               camera;
    TT_CamTargetAnimated    cam_target;
    TT_FogAnimated          fog;
    void                    scaleScene();

    //---------------------------------------------- Particles
    
    MSAParticleSystemEvented ps;
    
    //---------------------------------------------- FLUID
    MSAFluidManagerApp          fluid;
    MSAPhysicsFluidUpdater3D    fluid_updater;
    
    
    //---------------------------------------------- OTHER UPDATERS
    
    MSAPhysicsUpdaterCollision  user_collisions;
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
    
    //------------------------------------------------ Presets
    void        nextPreset();
    TT_Presets  my_presets;
    
    //------------------------------------------------ Sequencer    
    TT_Sequencer_Quiet    seq;
    
    //------------------------------------------------ OFXOPENNI
    
    TT_Player       oniPlayer;
    TT_UserManager  userManager;
    
    
};






