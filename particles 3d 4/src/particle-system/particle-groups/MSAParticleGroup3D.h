

#pragma once
#include "MSAPhysics3D.h"
#include "MSAPhysicsParticle.h"
#include "TT_Custom_MSAParticle3D.h"
#include "ofxSimpleGuiToo.h"

using namespace MSA;

class MSAParticleGroup3D {
    
public:
    
    MSAParticleGroup3D(){
        instance_name = "No Name yet!";
    };
    
    virtual void    setup();
    virtual void    update();
    virtual void    draw();
    virtual void    setParticleProperties( TT_Custom_MSAParticle3D * _p );
    
    virtual void    addParticle( TT_Custom_MSAParticle3D * p );
    virtual void    resizeParticleGroup();
    void            killParticles();
    
    //------------------------------------------------- Settings
    virtual void    addSettings( ofxSimpleGuiToo & _gui );
    void            setInstanceName( string _instance_name )
    {
        instance_name = _instance_name;
    };
    
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
    
    vector<TT_Custom_MSAParticle3D*>        group;
    
    string                                  instance_name;
    
};