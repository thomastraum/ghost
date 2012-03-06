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

    ofImage     texture;
    ofVbo       vbo;
    
    int         gl_point_size;

public:
    
    MSAParticleGroup3DMesh_PointSprites() {
        
        mesh.setMode(OF_PRIMITIVE_POINTS);
        ofDisableArbTex();
//        texture.loadImage("ps-1.png");
//        texture.loadImage("pt-8-black.png");
        texture.loadImage("pt-8.png");
        
        gl_point_size = 4;
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
        mesh.addVertex( ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
        mesh.addColor( ofColor(255,255,255 ) ); //ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)) );
    }
    
    //---------------------------------------------------------------
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index ) 
    {
        mesh.setVertex( index, ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
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
        vbo.draw( GL_POINTS, 0, mesh.getNumVertices() );
        texture.getTextureReference().unbind();		// new in OF006
        
//        glDisable(GL_ALPHA_TEST);
//        glDisable(GL_DEPTH_TEST);
        
        ofDisablePointSprites();
        ofDisableAlphaBlending();
    }
    
};