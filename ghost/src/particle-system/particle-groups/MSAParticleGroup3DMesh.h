//----------------------------------------------------------------
//  MSAParticleGroup3DMesh.h
//  particles 3d 3
//
//  Created by Thomas Eberwein on 16/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
//----------------------------------------------------------------
// Abstract class for particle groups that use a mesh and a VBO
// Do not inherit directly 
//----------------------------------------------------------------


#pragma once
#include "ofMain.h"
#include "MSAParticleGroup3D.h"
    
class MSAParticleGroup3DMesh : public MSAParticleGroup3D {

protected: 
    
    ofMesh  mesh;
    
public:
    
    MSAParticleGroup3DMesh () {
    }
    
    //-------------------------------------------------------------------------
    virtual void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3D::setParticleProperties( _p );
        addParticleToMesh( _p );
    }

    //-------------------------------------------------------------------------
    virtual void update() 
    {
        MSAParticleGroup3D::update();
        
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            if ( p->isDead() ) {
                it = group.erase(it);
                deleteInMesh( p,i );
            } else {   
                updateIndexWithParticle( p, i );
                i++;
                it++;
            }
        }
    };

    //-------------------------------------------------------------------------
    void resizeParticleGroup()
    {
        MSAParticleGroup3D::resizeParticleGroup();
        mesh.clear();
        
        // we recreate all the vertices as we cleared the whole mesh before //
        // we do this so we have a faster update loop //
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            addParticleToMesh( p );
            it++;
        }
    }

    //------------------------------------------------------------------------- Virtual
    // implemented in child classes
    virtual void addParticleToMesh( TT_Custom_MSAParticle3D * _p ){};
    
    //-------------------------------------------------------------------------
    // implemented in child classes
    virtual void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index ){};
    
    //-------------------------------------------------------------------------
    // implemented in child classes
    virtual void deleteInMesh( TT_Custom_MSAParticle3D * _p, int _index )
    {
        vector<ofVec3f>& verts = mesh.getVertices();
        verts.erase(verts.begin()+_index);
    };
    

    
};