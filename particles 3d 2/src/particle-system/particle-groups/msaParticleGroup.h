

#pragma once
#include "MSAPhysics3D.h"
#include "MSAPhysicsParticle.h"
#include "tt-custom-msaparticle.h"
#include "ofxSimpleGuiToo.h"

using namespace MSA;

class MSAParticleGroup3D {
    
public:
    
    MSAParticleGroup3D(){
        cout << "MSAParticleGroup3D contructor" << endl;
    };
    
    virtual void    setup();
    virtual void    update();
    virtual void    draw();
    virtual void    setParticleProperties( TT_Custom_MSAParticle * _p );
    
    virtual void    addParticle( TT_Custom_MSAParticle * p );
    void            resizeParticleGroup();
    void            killParticles();
    
    //------------------------------------------------- Settings
    virtual void    addSettings( string _instance_name, ofxSimpleGuiToo & _gui );
    
    
    //------------------------------------------------- Variables
    
protected:
    
    int                                     max_particles;
    
    //------------------------------------------------- Settings for particle group
    
    float                                   mass_min;
    float                                   mass_max;
    
    float                                   bounce_min;
    float                                   bounce_max;
    
    float                                   node_min;
    float                                   node_max;
    
    float                                   drag_min;
    float                                   drag_max;
    
    int                                     particle_default_color;
    
    bool                                    enable_collision;
    bool                                    enable_wrapping;
    
    vector<TT_Custom_MSAParticle*>          group;
    
};