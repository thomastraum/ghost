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
}


//--------------------------------------------------------------
void testApp::update(){

    ps.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
//    ofEnableAlphaBlending();
//    glEnable(GL_DEPTH_TEST);    
//    glEnable(GL_LIGHTING);
    
    camera.begin();
    ofTranslate( 0,0, -width);
    
    plane_top.draw();
    plane_left.draw();
    plane_right.draw();
    plane_back.draw();
    plane_bottom.draw();
    
    ofSetColor(255,0,0);
    ofBox( 0,0,0, 10 );

    ps.draw();
    
    camera.end();

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
