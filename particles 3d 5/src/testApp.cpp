#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){    
    
    ofSetLogLevel(OF_LOG_ERROR);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
    
    draw_debug = false;
    
    camera.setNearClip( -width );
    camera.setFarClip( width );
//    fog.setup();
    
    buildScene();
    
    ps.setup();
    fluid.setup();
    fluid_updater.setup( fluid.getSolver() );
    ps.addUpdater( &fluid_updater );
    ps.addUpdater( &shaker );
    
    
    //-------------------------------------         SETTINGS
    
    addAppSettings();
    
    preset_path     = "presets/";
    loadXMLSettingsFromPath( preset_path + my_presets.getNextPresetName() );
    
    //-------------------------------------
    
//    ofToggleFullscreen();
}

//--------------------------------------------------------------
void testApp::update()
{
    ps.update();
    fluid.update();
    
    if ( shaker.isShaking() )
        shaker.stopShaking();
    
}

//--------------------------------------------------------------
void testApp::draw()
{
//    ofEnableAlphaBlending();
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING);
    
    ofBackground(0, 0, 0);
    
    camera.begin();
    ofTranslate( 0,0, -width);
    
    fog.draw();
    
    ofSetColor(255,255,255);
    box.draw();
//    plane_top.draw();
//    plane_left.draw();
//    plane_right.draw();
//    plane_back.draw();
//    plane_bottom.draw();
    
    ofSetColor(255,0,0);
    ofPushMatrix();
    ofBox( 0,0,0, 10 );
    ofPopMatrix();
    
    ps.draw();
    
    camera.end();
    
    fluid.draw();
    
    gui.draw();
    
}

//--------------------------------------------------------------
void testApp::buildScene()
{
	width = ofGetWidth();
	height = ofGetHeight();
    
    fog.defineStartAndEnd( width, width*1.8 );
    
    box.width = width;
    box.height = height;
    
    box.build();    
}

//--------------------------------------------------------------
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
        ps.addLines( Vec3f( 0,0,0 ), 1000 );
    
    if (key=='q')
        ps.addQuads( Vec3f( 0,0,0 ), 1000 );
    
    if (key=='p')
        ps.addPoints( Vec3f( 0,0,0 ), 1000 );

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
    
    
//	if (key=='s')
//		savedPose = camera.getGlobalTransformMatrix();
//	
//	if (key=='l')
//		camera.setTransformMatrix(savedPose);
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    buildScene();
}

//-------------------------------------------------------------- SETTINGS
void testApp::addAppSettings()
{ 
    float slider_smoothing = 0.5;
    
    gui.setDefaultKeys(true);
    
    addMainSettings();
    
    fluid.addSettings( gui );
    ps.addSettings( gui );
    
}

//-------------------------------------------------------------- 
void testApp::addMainSettings()
{
    box.addSettings( gui );
    fog.addSettings( gui );
    fluid_updater.addSettings(gui);
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
    
    loadXMLSettings();
    
//	gui.setAutoSave(false);
    gui.show();
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











