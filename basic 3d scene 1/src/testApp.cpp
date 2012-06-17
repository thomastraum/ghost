#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){    
    
    ofSetLogLevel(OF_LOG_ERROR);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
	ofBackground(100, 100, 100);
    
    for ( int i=0; i<100; i++ ) {
        Particle * p = new Particle();
        p->x = ofRandom( -ofGetWidth()/2, ofGetWidth()/2 );
        p->y = ofRandom( -ofGetHeight()/2, ofGetHeight()/2 );
        p->z = ofRandom( -ofGetHeight()/2, ofGetHeight()/2 );
        particles.push_back( p );
    }
    
}


//--------------------------------------------------------------
void testApp::update(){

    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    camera.begin();
    
    ofSetColor(255,0,0);
    ofPushMatrix();
    ofBox( 0,0,0, 50 );
    ofPopMatrix();
    
    drawParticles();
    
    //    ps.draw();
    
    camera.end();
    
}

void testApp::drawParticles()
{

//    int i=0;
//    int max = particles.size();
//    vector<Particle*>::iterator it = particles.begin();
//    
//    while ( i < max ) {
//        
//        Particle * p = particles[i];
//        
//        if ( ofRandom(1) > .9 ) {
//            it = particles.erase(it);
//            max = particles.size();
//            //            end = particles.end();
//        } else {
//            ofSetColor(255, 255, 0);
//            ofCircle( p->x, p->y, p->z, 10);
//            
//            if ( ofRandom(1) < .1 ) addSomeNewOnes();
//            i++;
//            it++;
//        }
//    }

    
    vector<Particle*>::iterator it = particles.end()-1;
    int i = particles.size();
    
    while ( it > 0 ) {
        
//        cout << i << endl;
        
        Particle * p = *it;
        if ( ofRandom(1) > .9 ) {
            particles.erase(it);
        } else {
            ofSetColor(255, 255, 0);
            ofCircle( p->x, p->y, p->z, 10);
//            if ( ofRandom(1) < .1 ) addSomeNewOnes();
        }
        i--;
        it--;
    }

}

void testApp::addSomeNewOnes()
{
    int max = ofRandom(4);
    
    for ( int i=0; i<max; i++ ) {
        Particle * p = new Particle();
        p->x = ofRandom( -ofGetWidth()/2, ofGetWidth()/2 );
        p->y = ofRandom( -ofGetHeight()/2, ofGetHeight()/2 );
        p->z = ofRandom( -ofGetHeight()/2, ofGetHeight()/2 );
        particles.push_back( p );
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
    
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
}
