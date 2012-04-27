//
//  MSAParticleSystem3D_Groups.h
//  particles 3d 3
//
//  Created by Thomas Eberwein on 16/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

//----------------------------------------------------------
// Implements MSAParticleSystem3D_Abstract
// allows multiple groups. 
// 
//----------------------------------------------------------


#pragma once
#include "MSAParticleSystem3D_Abstract.h"
#include "MSAParticleGroup3D_PointSpritesShader.h"
#include "MSAParticleGroup3DMesh_Lines.h"
#include "MSAParticleGroup3D_Fixed.h"

class MSAParticleSystem3D_Groups : public MSAParticleSystem3D_Abstract {

private :
    
    MSAParticleGroup3D * quads;
    MSAParticleGroup3D * lines;
    MSAParticleGroup3D * colliders;
    
    MSAParticleGroup3D * active_group;
    
public:
    
    MSAParticleSystem3D_Groups(){
        active_group    = 0;
        quads           = 0;
        lines           = 0;
        colliders       = 0;
    };
    
    void addQuads( Vec3f _pos, int _count ) 
    {
        active_group = quads;
        addParticles( _pos, _count );
    };
    
    void addLines( Vec3f _pos, int _count ) 
    {
        active_group = lines;
        addParticles( _pos, _count );
    };
    
    TT_Custom_MSAParticle3D * addCollider( Vec3f _pos ) 
    {
        active_group = colliders;
        return addParticle( _pos );
    };
    
protected :
    
    void createParticleGroups() 
    {
        quads = new MSAParticleGroup3D_PointSpritesShader();
        quads->setup();
        quads->setInstanceName( "PS Shader" );
        groups.push_back(quads);
        
        lines = new MSAParticleGroup3DMesh_Lines(); 
        lines->setup();
        lines->setInstanceName( "Lines" );
        groups.push_back(lines);
        
        colliders = new MSAParticleGroup3D_Fixed(); 
        colliders->setup();
        colliders->setInstanceName( "Colliders" );
        groups.push_back(colliders);
        
        active_group = quads;
    }
    
    // -----------------------------------------------------  PARTICLES
    // overriding from abstract
    TT_Custom_MSAParticle3D * addParticle( Vec3f _pos )
    {
        TT_Custom_MSAParticle3D * p = createParticle(_pos);
        active_group->addParticle( p );
        p->release();
        return p;
    }
    
    // override
    void addParticles( Vec3f _pos, int _count )
    {
        int max_x = width*2;
        int max_y = height;
        
        for(int i=0; i<_count; i++)
            addParticle( Vec3f( _pos.x + ofRandom(-max_x, max_x), _pos.y + ofRandom(-max_y,max_y), _pos.z + ofRandom(max_x,-max_x)) );
            //addParticle( Vec3f( _pos.x , _pos.y, _pos.z ) ); // + Rand::randVec3f() * 300 );
    };
    
    

};