//
//  MSAParticleSystem3D_tt.h
//  particles 3d 3
//
//  Created by Thomas Eberwein on 16/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

//----------------------------------------------------------
// Implements MSAParticleSystem3D_Abstract
// allows multipls groups. 
// 
//----------------------------------------------------------


#pragma once
#include "MSAParticleSystem3D_Abstract.h"

class MSAParticleSystem3D_tt : public MSAParticleSystem3D_Abstract {

private :
    
    MSAParticleGroup3D * quads;
    MSAParticleGroup3D * lines;
    MSAParticleGroup3D * points;
    
    MSAParticleGroup3D * active_group;
    
public:
    
    MSAParticleSystem3D_tt(){
        active_group = 0;
        quads = 0;
        lines = 0;
        points = 0;
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
    
    void addPoints( Vec3f _pos, int _count ) 
    {
        active_group = points;
        addParticles( _pos, _count );
    };
    
    
protected :
    
    void createParticleGroups() 
    {
        quads = new MSAParticleGroup3DMesh_Quad();
        quads->setup();
        quads->setInstanceName( "Quads" );
        groups.push_back(quads);
        
        lines = new MSAParticleGroup3DMesh_Lines(); 
        lines->setup();
        lines->setInstanceName( "Lines" );
        groups.push_back(lines);
        
        points = new MSAParticleGroup3DMesh_PointSprites();
        points->setup();
        points->setInstanceName( "Point Sprites" );
        groups.push_back(points);
        
        active_group = quads;
    }
    
    void addParticle( Vec3f _pos )
    {
        TT_Custom_MSAParticle3D * p = createParticle(_pos);
        active_group->addParticle( p );
        p->release();
    }

};