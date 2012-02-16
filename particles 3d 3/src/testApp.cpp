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
    loadXMLSettings();
    
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
    
    if (draw_debug) {
    
        ofSetColor(255,255,255);
        plane_top.draw();
        plane_left.draw();
        plane_right.draw();
        plane_back.draw();
        plane_bottom.draw();
        
        ofSetColor(255,0,0);
        ofPushMatrix();
        ofRotateX(25);
        ofRotateY(49);
        ofBox( 0,0,0, 10 );
        ofPopMatrix();
    }
    
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
    
    fog.defineStartAndEnd( 0, width*1.9 );
    
    plane_bottom.width = width;
    plane_bottom.height = height;
    
    plane_left.width = height;
    plane_left.height = height;
    
    plane_top.width = width;
    plane_top.height = height;
    
    plane_right.width = height;
    plane_right.height = height;
    
    plane_back.width = width;
    plane_back.height = height;
    
    
    // Position planes
//    plane_bottom.rotate(90, plane_bottom.getXAxis() );
//    plane_bottom.move(0, height, 0);
    plane_bottom.setPosition(0, -height, 0);
    plane_bottom.setOrientation(ofVec3f(90,0,0));
    
    
//    plane_left.rotate(90, plane_left.getYAxis() );
//    plane_left.move(-width,0, 0);
    plane_left.setPosition(-width, 0, 0);
    plane_left.setOrientation(ofVec3f(0,90,0));
    
        
//    plane_top.rotate(90, plane_bottom.getXAxis() );
//    plane_top.move(0, -height, 0);
    plane_top.setPosition(0, height, 0);
    plane_top.setOrientation(ofVec3f(90,0,0));
    
    
//    plane_right.rotate(90, plane_right.getYAxis() );
//    plane_right.move(width, 0, 0);
    plane_right.setPosition(width, 0, 0);
    plane_right.setOrientation(ofVec3f(0,90,0));
    
//    plane_back.move(0, 0, -height);
    plane_back.setPosition(0, 0, -height);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key== 'd' )
        draw_debug = ! draw_debug;
    
	if (key=='c')
		camera.toggleCursorDraw();
	
	if (key=='u')
		camera.toggleFixUpwards();
    
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
    float slider_smoothing = 0.9;
    
    gui.setDefaultKeys(true);
	gui.setAutoSave(false);
    
    fog.addSettings( gui );
//    fog.color = ofFloatColor( 1,1,1,1);
//	gui.addColorPicker("Fog Color Red", &fog.color.r);
	
//	gui.addColorPicker("Plane Color R", &plane_color.r);
//	gui.addColorPicker("Plane Color G", &plane_color.g);
//	gui.addColorPicker("Plane Color B", &plane_color.b);
    
    fluid.addSettings( gui );
    fluid_updater.addSettings(gui);
    
    ps.addSettings( gui );
}

void testApp::loadXMLSettings()
{
    gui.loadFromXML();
}
