#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){    
    
    ofSetLogLevel(OF_LOG_ERROR);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
	ofBackground(100, 100, 100);
    
    buildScene();
    
    ps.setup();
    
    //-------------------------------------         SETTINGS
    
    addAppSettings();
    ps.addSettings( gui );
    loadXMLSettings();
}

//--------------------------------------------------------------
void testApp::update(){
    ps.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);    
//    glEnable(GL_LIGHTING);
    
    ofBackground(0, 0, 0);
    
    camera.begin();
    ofTranslate( 0,0, -width);
    
    ofSetColor(255,255,255);
    plane_top.draw();
    plane_left.draw();
    plane_right.draw();
    plane_back.draw();
    plane_bottom.draw();
    
    ofSetColor(255,0,0);
    ofBox( 0,0,0, 10 );
    
    ps.draw();
    
    camera.end();
    
    gui.draw();
    
}

//--------------------------------------------------------------
void testApp::buildScene()
{
	width = ofGetWidth();
	height = ofGetHeight();
    
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
	
	if (key=='c')
		camera.toggleCursorDraw();
	
	if (key=='u')
		camera.toggleFixUpwards();
    
    if (key=='f')
		ofToggleFullscreen();
    
    if (key=='p')
        ps.addParticles( Vec3f( 0,0,0 ), 1000 );
    
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
    
//    gui.addSlider("fluidCellsX", fluidCellsX, 20, 400);
//	gui.addButton("resizeFluid", resizeFluid);
//	gui.addSlider("fs.viscocity", fluidsolver.viscocity, 0.0, 0.001); 
//	gui.addSlider("fs.colorDiffusion", fluidsolver.colorDiffusion, 0.0, 0.0003); 
//	gui.addSlider("fs.fadeSpeed", fluidsolver.fadeSpeed, 0.0, 0.1); 
//	gui.addSlider("fs.solverIterations", fluidsolver.solverIterations, 1, 50); 
//	gui.addSlider("fs.deltaT", fluidsolver.deltaT, 0.1, 5);
//    gui.addComboBox("fd.drawMode", (int&)fluidDrawer.drawMode, kFluidDrawCount, (string*)FluidDrawerGl::drawOptionTitles);
//	gui.addToggle("fs.doRGB", fluidsolver.doRGB); 
//	gui.addToggle("fs.doVorticityConfinement", fluidsolver.doVorticityConfinement); 
//	gui.addToggle("drawFluid", drawFluid);
//	gui.addToggle("fs.wrapX", fluidsolver.wrap_x);
//	gui.addToggle("fs.wrapY", fluidsolver.wrap_y);
	gui.addSlider("Particle Num", ps.numberOfParticles, 0, 100000 );
    
//    gui.addSlider( "Force Multiplier", fixedforce_power, 0, 0.1).setSmoothing( slider_smoothing );
    
//    main_page = & gui.currentPage();
//    main_page->setXMLName( "settings_main.xml" );
}

void testApp::loadXMLSettings()
{
    gui.loadFromXML();
}
