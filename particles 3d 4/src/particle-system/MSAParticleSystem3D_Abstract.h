
#pragma once
#include "ofMain.h"
#include "MSAPhysics3D.h"
#include "MSAParticleGroups3D_Quads.h"
#include "MSAParticleGroup3DMesh_Quad.h"
#include "MSAParticleGroup3DMesh_PointSprites.h"
#include "MSAParticleGroup3DMesh_Lines.h"

using namespace MSA;

#define MAX_USERS 1

class MSAParticleSystem3D_Abstract  {

public:
    
    MSAParticleSystem3D_Abstract(){
    };
    
    void setup();
    void update();
    void draw();
    
    void addParticles( Vec3f _pos, int _count );
    
    void addUpdater( Physics::ParticleUpdater3D * _updater );
    void killAll();
    
    //---------------------------------------------------- EVENTS
    void windowResized( ofResizeEventArgs&args );

    //---------------------------------------------------- SETTINGS
    virtual void addSettings( ofxSimpleGuiToo & _gui );
    virtual void setXMLFilename( string _xml_filename );
    
    bool                        update_gravity;
    
protected:
    
    vector<MSAParticleGroup3D*> groups;
    
    // overload this if you want to add your own particle groups // 
    virtual void createParticleGroups();
    virtual void addParticle( Vec3f _pos );
    
    TT_Custom_MSAParticle3D *   createParticle( Vec3f _pos );
    
    float                       gravity;
    int                         width;
    int                         height;
    
private:
    
    Physics::World3D    physics;
    void                initScene();
    void                resizeScene();
    
    // -------------------------------------------------- PARTICLES
    
    
    MSAParticleGroup3D *        defaultgroup;
    
    
    Physics::Particle3D         mouse_node;
    void                        addMouseParticle();
    void                        moveMouseParticle( int x, int y, int z );
    
    int                         numberOfParticles;
    
    //---------------------------------------------------- CONSTRAINTS
    
    
    //---------------------------------------------------- SETTINGS
    string                      xml_filename;
    ofxSimpleGuiPage *          gui_particle_page;
        
};