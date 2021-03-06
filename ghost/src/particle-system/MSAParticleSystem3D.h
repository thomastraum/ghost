
#pragma once
#include "ofMain.h"
#include "MSAPhysics3D.h"
//#include "MSAParticleGroup3D_PointSpritesVBO.h"
//#include "MSAParticleGroup3D_Lines.h"
#include "MSAParticleGroups3D_Quads.h"
#include "MSAParticleGroup3DMesh_Quad.h"
#include "MSAParticleGroup3DMesh_PointSprites.h"
#include "MSAParticleGroup3DMesh_Lines.h"

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
    
    // overload this if you want to add your own particle groups // 
    virtual void createParticleGroups();
    
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
    vector<MSAParticleGroup3D*> groups;
    
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