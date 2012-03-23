//
//  MSAParticleGroup3DMesh_Lines.h
//  particles 3d 3
//
//  Created by Thomas Eberwein on 16/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "MSAParticleGroup3DMesh.h"

class MSAParticleGroup3DMesh_Lines : public MSAParticleGroup3DMesh {

private:
    
    ofImage     texture;
    ofVbo       vbo;
    
    // !! different types in the PS !! //
    
    Vec3f           pos_vec3f;
    ofVec3f         pos;
    
    Vec3f           prev_pos_vec3f;
    ofVec3f         prev_pos;
    
    ofFloatColor    color;
    
public:
    
    MSAParticleGroup3DMesh_Lines() {
        mesh.setMode( OF_PRIMITIVE_LINES );
        color = ofFloatColor(1,1,1,1 );
    }
    
    void addParticleToMesh( TT_Custom_MSAParticle3D * _p )
    {
        pos_vec3f = _p->getPosition();
        pos =  ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
        
        mesh.addVertex( pos );
        mesh.addVertex( pos );
        
        mesh.addColor( color );
        mesh.addColor( color ); 
    }
    
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index ) 
    {
        pos_vec3f       = _p->getPosition();
        prev_pos_vec3f  = _p->getPosition() - _p->getVelocity();
        color.a         = _p->getAlpha();
        
        pos         = ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
        prev_pos    = ofVec3f( prev_pos_vec3f.x, prev_pos_vec3f.y, prev_pos_vec3f.z );
        
        int i = index * 2;
        
        mesh.setColor( i, color );
        mesh.setVertex( i++, prev_pos );
        
        mesh.setColor( i, color );
        mesh.setVertex( i++, pos );
    };
    
    void draw()
    {
        ofEnableAlphaBlending();
//      glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
        
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_LINES, 0, group.size() ); //mesh.getNumVertices() );
        
//      glDisable(GL_DEPTH_TEST);
        ofDisableAlphaBlending();
    }
};