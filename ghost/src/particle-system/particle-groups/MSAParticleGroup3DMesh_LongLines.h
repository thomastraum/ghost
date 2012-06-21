//
//  MSAParticleGroup3DMesh_LongLines.h
//  ghost
//
//  Created by Thomas Eberwein on 17/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_MSAParticleGroup3DMesh_LongLines_h
#define ghost_MSAParticleGroup3DMesh_LongLines_h

#pragma once
#include "MSAParticleGroup3DMesh.h"

class MSAParticleGroup3DMesh_LongLines : public MSAParticleGroup3DMesh {
    
private:
    
    ofImage     texture;
    ofVbo       vbo;
    
    // !! different types in the PS !! //
    Vec3f           pos_vec3f;
    ofVec3f         pos;
    Vec3f           prev_pos_vec3f;
    ofVec3f         prev_pos;
    
    ofFloatColor    color;
    int             line_length;
    
public:
    
    MSAParticleGroup3DMesh_LongLines() {
        mesh.setMode( OF_PRIMITIVE_LINES );
        color = ofFloatColor(1,0,1,1 );
        line_length = 10;
    }
    
    void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
//        _p->enableFadeOut();
        _p->setNumberOfSavedPositions( line_length ); //(int)ofRandom(line_length/2, line_length) );
        
        MSAParticleGroup3DMesh::setParticleProperties( _p );        
    }
    
    void addParticleToMesh( TT_Custom_MSAParticle3D * _p )
    {
        pos_vec3f = _p->getPosition();
        pos =  ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
        
        int max = _p->pos_length;
        for (int i=0; i<max; i++) {
            pos_vec3f = _p->pos[i];
            mesh.addVertex( ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z ) );
            mesh.addColor( _p->getColor() ); 
        }
    }
    
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int _index ) 
    {
        pos_vec3f = _p->getPosition();
        pos = ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
        
        // scale index to mesh offset //
        int mesh_index =  _index * _p->pos_length;
        int max = mesh_index + _p->pos_length;
        
        // have j as index for positions in line particle //
        int j=0;
        for (int i=mesh_index; i<max; i++) {
            pos_vec3f = _p->pos[j];
            mesh.setVertex( i, ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z ) );
            j++;
        }        
    };
    
    virtual void deleteInMesh( TT_Custom_MSAParticle3D * _p, int _index )
    {
        vector<ofVec3f>& verts = mesh.getVertices();
        
        // scale index to mesh offset //
        int mesh_index =  _index * _p->pos_length;
        int max = mesh_index + _p->pos_length;
        
        // have j as index for positions in line particle //
        int j=0;
        for (int i=mesh_index; i<max; i++) {
            verts.erase(verts.begin()+i);
            j++;
        }  
    };
    
    void draw()
    {
        ofEnableAlphaBlending();
        //      glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
        glLineWidth(3);
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_LINES, 0, mesh.getNumVertices() );
        
        //      glDisable(GL_DEPTH_TEST);
        ofDisableAlphaBlending();
    }
};

#endif
