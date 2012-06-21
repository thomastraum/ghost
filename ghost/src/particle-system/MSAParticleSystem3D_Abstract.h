
#pragma once
#include "ofMain.h"
#include "MSAPhysics3D.h"
#include "MSAParticleGroup3D.h"

using namespace MSA;

#define MAX_USERS 1

class MSAParticleSystem3D_Abstract  {

public:
    
    MSAParticleSystem3D_Abstract(){
    };
    
    void setup();
    virtual void update();
    void draw();
    
    void addUpdater( Physics::ParticleUpdater3D * _updater );
    void removeUpdater( Physics::ParticleUpdater3D * _updater );
    void killAll();
    
    //---------------------------------------------------- EVENTS
    void windowResized( ofResizeEventArgs&args );

    //---------------------------------------------------- SETTINGS
    virtual void addSettings( ofxSimpleGuiToo & _gui );
    virtual void setXMLFilename( string _xml_filename );
    
protected:
    
    vector<MSAParticleGroup3D*> groups;
    
    // overload these if you want to add your own particle groups and 
    // where to put them
    virtual void                        createParticleGroups();
    virtual TT_Custom_MSAParticle3D *   addParticle( Vec3f _pos );
    virtual void                        addParticles( Vec3f _pos, int _count );
    
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
    float                       prev_gravity;               // this is ugly but i need to know when the gravity changes
        
};