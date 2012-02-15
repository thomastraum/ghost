//
//  MSAParticleGroup3D_Lines.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 15/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef particles_3d_2_MSAParticleGroup3D_Lines
#define particles_3d_2_MSAParticleGroup3D_Lines

#pragma once
#include "ofMain.h"
#include "MSAParticleGroup3D.h"

class MSAParticleGroup3D_Lines : public MSAParticleGroup3D {
    
    ofMesh      mesh;
    ofImage     texture;
    ofVbo       vbo;
    
    Vec3f       pos, vel;
    ofVec3f     of_pos;
    
public:
    
    MSAParticleGroup3D_Lines() {   
        mesh.clear();
        mesh.setMode( OF_PRIMITIVE_POINTS );
    }
    
    void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3D::setParticleProperties( _p );
        
        mesh.addVertex( ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
        mesh.addVertex( ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
        
        mesh.addColor( ofColor(255,255,255 ) ); //ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)) );
        mesh.addColor( ofColor(255,255,255 ) ); //ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)) );
    }
    
    void update() {
        
        Vec3f prev_pos;
        
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        while( it != group.end() ) {
            
            TT_Custom_MSAParticle3D * p = *it;

            prev_pos = p->getPosition() - p->getVelocity();
            mesh.setVertex( i++, ofVec3f( prev_pos.x, prev_pos.y, prev_pos.z ) );
            mesh.setVertex( i++, ofVec3f( p->getPosition().x, p->getPosition().y, p->getPosition().z ) );
            
//            pos = p->getPosition() - p->getVelocity();
//            mesh.setVertex( i++, vec3fToOfVec3f(pos) );

//            pos = p->getPosition();
//            mesh.setVertex( i++, vec3fToOfVec3f(pos) );
            
            it++;
        }
        
    };
    
    void draw()
    {
        ofEnableAlphaBlending();
//        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
        
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_LINES, 0, mesh.getNumVertices() );
        
//        glDisable(GL_ALPHA_TEST);
//        glDisable(GL_DEPTH_TEST);
        ofDisableAlphaBlending();
    }
    
    virtual void resizeParticleGroup()
    {
        MSAParticleGroup3D::resizeParticleGroup();
        mesh.clearVertices();
    }
                           
                           
    ofVec3f vec3fToOfVec3f( Vec3f _vec )
    {
       ofVec3f vec;
       
       vec.x = _vec.x;
       vec.y = _vec.x;
       vec.z = _vec.x;
       
       return vec;
    }
};


#endif

