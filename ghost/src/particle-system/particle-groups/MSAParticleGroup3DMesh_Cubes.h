//
//  MSAParticleGroup3DMesh_Cubes.h
//  ghost
//
//  Created by Thomas Eberwein on 18/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_MSAParticleGroup3DMesh_Cubes_h
#define ghost_MSAParticleGroup3DMesh_Cubes_h

#pragma once
#include "MSAParticleGroup3DMesh.h"

class MSAParticleGroup3DMesh_Cubes : public MSAParticleGroup3DMesh {
    
private:
    
    ofImage     texture;
    ofVbo       vbo;
    
    // !! different types in the PS !! //
    
    Vec3f           pos_vec3f;
    ofVec3f         pos;
    
    Vec3f           prev_pos_vec3f;
    ofVec3f         prev_pos;
    
public:
    
    MSAParticleGroup3DMesh_Cubes() {
//        mesh.setMode( OF_TRIANGLES );
    }
    
    virtual void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
//        _p->enableFadeOut();
        MSAParticleGroup3DMesh::setParticleProperties( _p );
    }
    
    void addParticleToMesh( TT_Custom_MSAParticle3D * _p )
    {
//        pos_vec3f = _p->getPosition();
//        pos =  ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
//        
//        mesh.addVertex( pos );
//        mesh.addVertex( pos );
//        
//        mesh.addColor( color );
//        mesh.addColor( color ); 
    }
    
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index ) 
    {
//        pos_vec3f       = _p->getPosition();
//        prev_pos_vec3f  = _p->getPosition() - _p->getVelocity();
//        color.a         = _p->getAlpha();
//        
//        pos         = ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
//        prev_pos    = ofVec3f( prev_pos_vec3f.x, prev_pos_vec3f.y, prev_pos_vec3f.z );
//        
//        int i = index * 2;
//        
//        mesh.setColor( i, color );
//        mesh.setVertex( i++, prev_pos );
//        
//        mesh.setColor( i, color );
//        mesh.setVertex( i++, pos );
    };
    
    void draw()
    {
        ofEnableAlphaBlending();
        glEnable(GL_DEPTH_TEST);
        
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        
        ofPushStyle();
        Vec3f pos;
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            ofFill();
            ofSetColor( p->getColor() );
            pos = p->getPosition();
            ofBox( pos.x,pos.y,pos.y, p->getRadius()*2 );
            it++;
        }
        
        ofPopStyle();
        
        glDisable(GL_DEPTH_TEST);
        ofDisableAlphaBlending();
    }
};

#endif
