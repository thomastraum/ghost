//
//  MSAParticleGroup3DMesh_PointSprites.h
//  particles 3d 3
//
//  Created by Thomas Eberwein on 16/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "MSAParticleGroup3DMesh.h"

class MSAParticleGroup3DMesh_PointSprites : public MSAParticleGroup3DMesh {

private:
    
    int             gl_point_size;
    
protected:

    ofImage         texture;
    ofVbo           vbo;
    
    ofFloatColor    color;
    Vec3f           pos_vec3f;
    ofVec3f         pos;

public:
    
    MSAParticleGroup3DMesh_PointSprites() {
        
        mesh.setMode(OF_PRIMITIVE_POINTS);
        ofDisableArbTex();
        texture.loadImage("pt-8.png");
        
        gl_point_size = 4;
        color = ofFloatColor(1,1,1,1 );
    }
    
    //---------------------------------------------------------------
    void addSettings( ofxSimpleGuiToo & _gui )
    {
        MSAParticleGroup3DMesh::addSettings( _gui );
        _gui.addSlider( "Point Size", gl_point_size, 1, 50);
    }
    
    //---------------------------------------------------------------
    void addParticleToMesh( TT_Custom_MSAParticle3D * _p )
    {
        pos_vec3f = _p->getPosition();
        pos =  ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
        mesh.addVertex( pos );
        mesh.addColor( color ); //ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)) );
    }
    
    //---------------------------------------------------------------
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index ) 
    {
        pos_vec3f   = _p->getPosition();
        color.a     = _p->getAlpha();
        
        pos = ofVec3f( pos_vec3f.x, pos_vec3f.y, pos_vec3f.z );
        mesh.setVertex( index, pos );
        mesh.setColor( index, color );
    };
    
    //---------------------------------------------------------------
    virtual void draw()
    {
        glPointSize( gl_point_size );
        
        ofEnablePointSprites();
        ofEnableAlphaBlending();
        
//        glEnable(GL_DEPTH_TEST);
//        glEnable(GL_ALPHA_TEST);
//        glAlphaFunc(GL_GREATER, 0.1);
        
        texture.getTextureReference().bind();
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_POINTS, 0, group.size() ); //mesh.getNumVertices() );
        texture.getTextureReference().unbind();
        
//        glDisable(GL_ALPHA_TEST);
//        glDisable(GL_DEPTH_TEST);
        
        ofDisablePointSprites();
        ofDisableAlphaBlending();
    }
    
};