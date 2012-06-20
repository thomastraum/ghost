#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){    
    
    ofSetLogLevel(OF_LOG_ERROR);
    ofSetLogLevel( "TT", OF_LOG_ERROR ); //OF_LOG_NOTICE );
    ofSetLogLevel( "TT-NI", OF_LOG_NOTICE );

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
    
    draw_debug = false;
    
    box.build();
    scaleScene();
    
    ps.setup();
    fluid.setup();
    fluid_updater.setup( fluid.getSolver() );
    ps.addUpdater( &fluid_updater );
    ps.addUpdater( &shaker );
    ps.addUpdater( &user_collisions );

    camera.setTarget(cam_target);
    
    //--------------------------------------------------- SETTINGS
    
    addAppSettings();
    preset_path     = "presets/";
    loadXMLSettingsFromPath( preset_path + my_presets.getNextPresetName() );
    
    //-------------------------------------
    
//    camera.setNearClip( 2*width );
//    camera.setFarClip( -2*width );
//    fog.setup();
//    ofToggleFullscreen();
    
    //--------------------------------------------------- SOUNDS

    sm.addLoop( "sounds/storm-tt-loop.wav" );
    sm.addLoop( "sounds/synths-tt-loop.wav" );
    
    sm.addEventSound("sounds/clarinet-jitter.wav");
    sm.addEventSound("sounds/clarinet-force-change-2.wav");
    sm.addEventSound("sounds/clarinet-soft.wav");
    sm.addEventSound("sounds/monolake-hall-1.wav");
    
    sm.addEventSound("sounds/damage-big-1.wav");
    sm.addEventSound("sounds/damage-heavy-1.wav");
    sm.addEventSound("sounds/damage-normal-1.wav");
    
    seq.start();
    
    //--------------------------------------------------- OFXOPENNI
    oniPlayer.play("openni/test.oni");
    
    
    //--------------------------------------------------- MISC
    
    //    box.fadeToColor( ofFloatColor(1,0,1), 10);
    //    box.flashUp( ofFloatColor(ofRandom(0,1),ofRandom(0,1),ofRandom(0,1)), 2.0 );
    
    ofSoundStopAll();
}

//--------------------------------------------------------------
void testApp::update()
{
    oniPlayer.update();
    userManager.update();
    
    user_collisions.calculateBoundingBox();
    
    ps.update();
    fluid.update();
    cam_target.update();
    
    if ( shaker.isShaking() ) shaker.stopShaking();

    seq.update();
}

//--------------------------------------------------------------
void testApp::draw()
{    
    ofBackground(0, 0, 0);
    
    camera.setDistance(width);
    camera.begin();
        
    fog.draw();
    
    ofSetColor(255,255,255);
    
    
    glEnable(GL_DEPTH_TEST);
    box.draw();
    cam_target.draw();
    userManager.draw();
    glDisable(GL_DEPTH_TEST);
    
    ps.draw();
    
    camera.end();
    
    fluid.draw();
    gui.draw();
//    sm.draw();
    
    oniPlayer.draw();

}

//--------------------------------------------------------------
void testApp::scaleScene()
{
	width = ofGetWidth();
	height = ofGetHeight();
    
//    fog.defineStart( width );
    
    box.width   = width*1.5;
    box.height  = height;

//    box.depth   = 2000; //width*4;
    
//    box.width   = 3000;
//    box.height  = 1500;
//    box.depth   = 4000;
}

//-------------------------------------------------------------- SETTINGS
void testApp::addAppSettings()
{ 
    float slider_smoothing = 0.5;
    
    gui.setDefaultKeys(true);
    
    addMainSettings();
    
    fluid.addSettings( gui );
    ps.addSettings( gui );
//    sm.addSettings( gui );
    
    seq.addSettings(gui);
    
}

//-------------------------------------------------------------- 
void testApp::addMainSettings()
{
    box.addSettings( gui );
    fog.addSettings( gui );
    fluid_updater.addSettings(gui);
    userManager.addSettings(gui);
    
    main_page = & gui.currentPage();
}

//-------------------------------------------------------------- 
void testApp::setXMLFilename( string _xml_filename )
{
    main_page->setXMLName( _xml_filename );
}

//--------------------------------------------------------------
void testApp::loadXMLSettingsFromPath( string _path )
{
    cout << "loadXMLSettingsFromPath: " + _path << endl;
    
    setXMLFilename( _path + "schnitzel.xml" );
    ps.setXMLFilename( _path + "Particle TT.xml" );
    fluid.setXMLFilename( _path + "MSAFluidManager_settings.xml" );
    seq.setXMLFilename(_path + "sequencer-1.xml");
    
    loadXMLSettings();
    
	gui.setAutoSave(false);
//    gui.show();
}

//-------------------------------------------------------------- 
void testApp::loadXMLSettings()
{
    gui.loadFromXML();
}

//-------------------------------------------------------------- PRESET
void testApp::nextPreset()
{
    loadXMLSettingsFromPath( preset_path + my_presets.getNextPresetName() );
}

//-------------------------------------------------------------- EVENTS
void testApp::keyPressed(int key){
    
    if (key== 'd' )
        draw_debug = ! draw_debug;
    
    //	if (key=='c')
    //		camera.toggleCursorDraw();
	
    //	if (key=='u')
    //		camera.toggleFixUpwards();
    
    if (key=='f')
		ofToggleFullscreen();
    
    //    if (key=='p')
    //        ps.addParticles( Vec3f( 0,0,0 ), 1000 );
    
    if (key=='l')
        ps.addLines( Vec3f( 0,0,0 ), 100, Vec3f(20,20,20), Vec3f( 100,100,1000) );
    
    if (key=='q')
        ps.addQuads( Vec3f( 0,0,0 ), 1000, Vec3f(width,height,height*2), Vec3f( 100,100,1000) );
    
    if (key=='p') {
        user_collisions.addToCollisionCheck( ps.addCollider(Vec3f(0,0,0)) );
    }
    
    if (key=='k')
        ps.killAll();
    
    if (key=='[' )
        gui.prevPage(); 
    
    if (key==']' )
        gui.prevPage(); 
    
    if (key=='[' )
        gui.prevPage(); 
    
    if (key=='[' )
        gui.prevPage(); 
    
    if (key=='0' || '9' )
        gui.setPage(key - '0');
    
    if ( key=='s' )
        shaker.startShaking();
    
    if ( key == '.' )
        nextPreset();
    
    if ( key == 'c' )
        box.flashUp( ofFloatColor( ofRandom(0,1),ofRandom(0,1),ofRandom(0,1) ), 0.4);
    
    if ( key == 'v' ) {
        sm.fadeLoopVolume( 0, 0, ofRandom(0,3) );
        //        sm.fadeLoopVolume( 1, 0, ofRandom(0,3) );
        sm.playEventSound( 1, 1 );
    }
    
    if ( key == 'b' ) {
        fluid.onFadeForceUpAndDown( 1, 0, 10 );
    }
    
    //    if (key=='n')
    //		savedPose = camera.getGlobalTransformMatrix();
    //	
    //	if (key=='m')
    //		camera.setTransformMatrix(savedPose);
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    scaleScene();
}










