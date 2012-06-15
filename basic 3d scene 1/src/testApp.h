#pragma once

#include "ofMain.h"
#include "particle.h"

class testApp : public ofBaseApp{

public:
    
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void windowResized(int w, int h);
    
    void drawParticles();
    void addSomeNewOnes();
    void deleteSome();
    
private:    
    
    int     width;
    int     height;
    
    
	ofEasyCam  camera;
    
    void        buildScene();
    
    vector<Particle*> particles; 
};

