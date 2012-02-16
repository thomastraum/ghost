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
    
    ofVec3f       pos;
    // !! different type in the PS !! //
    Vec3f       prev_pos;
    
public:
    
    MSAParticleGroup3DMesh_Lines() {
        mesh.setMode( OF_PRIMITIVE_LINES );
    }
    
    void addParticleToMesh( TT_Custom_MSAParticle3D * _p )
    {
        pos =  ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z );
        
        mesh.addVertex( pos );
        mesh.addVertex( pos );
        
        mesh.addColor( ofColor(255,255,255 ) );
        mesh.addColor( ofColor(255,255,255 ) ); 
    }
    
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index ) 
    {
        prev_pos = _p->getPosition() - _p->getVelocity();
        
        int i = index * 2;
        mesh.setVertex( i++, ofVec3f( prev_pos.x, prev_pos.y, prev_pos.z ) );
        mesh.setVertex( i++, ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
    };
    
    void draw()
    {
        ofEnableAlphaBlending();
//      glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
        
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_LINES, 0, mesh.getNumVertices() );
        
//      glDisable(GL_ALPHA_TEST);
//      glDisable(GL_DEPTH_TEST);
        ofDisableAlphaBlending();
    }
};