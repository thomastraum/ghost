
#pragma once
#include "ofMain.h"
#include "MSAPhysics3D.h"
#include "MSAParticleGroup3D_PointSpritesVBO.h"
#include "MSAParticleGroup3D_Lines.h"
#include "MSAParticleGroups3D_Quads.h"

using namespace MSA;

#define MAX_USERS 1

class MSAParticleSystem3D  {

public:
    
    MSAParticleSystem3D(){
    };
    
    void setup();
    void update();
    void draw();
    
    // -------------------------------------------------- PARTICLES
    
    void initScene();
    void resizeScene();
    
    void createParticleGroups();
    void addParticles( Vec3f _pos, int _count );
    void addParticle( Vec3f _pos  );
    
    void addMouseParticle();
    void killAll();
    
    void addUpdater( Physics::ParticleUpdater3D * _updater );
    
    TT_Custom_MSAParticle3D *   createParticle( Vec3f _pos );
    void                        moveMouseParticle( int x, int y, int z );
    
    Physics::World3D            physics;
    
    float                       gravity;
    int                         numberOfParticles;
    
    MSAParticleGroup3D *        maingroup;
    Physics::Particle3D         mouse_node;
    
    int                         width;
    int                         height;
    
    //---------------------------------------------------- CONSTRAINTS
    
    //---------------------------------------------------- SETTINGS
    virtual void                addSettings( ofxSimpleGuiToo & _gui );
    virtual void                setXMLFilename( string _xml_filename );
    
    string                      xml_filename;
    ofxSimpleGuiPage *          gui_particle_page;
    bool                        update_gravity;
    
    //---------------------------------------------------- EVENTS
    void windowResized( ofResizeEventArgs&args );
    
};