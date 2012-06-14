//
//  MSAParticleGroup3D_PointSpritesShader.h
//  ghost
//
//  Created by Thomas Eberwein on 03/04/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef ghost_MSAParticleGroup3D_PointSpritesShader_h
#define ghost_MSAParticleGroup3D_PointSpritesShader_h

#pragma once
#include "MSAParticleGroup3DMesh_PointSprites.h"

class MSAParticleGroup3D_PointSpritesShader : public MSAParticleGroup3DMesh_PointSprites {
    
private:
    
    ofShader shader;
    float    point_sizes[30000];
    float    colors[30000*3];
    
public:
    
    MSAParticleGroup3D_PointSpritesShader() {
        
        shader.load( "shaders/pointsprites.vert", "shaders/pointsprites.frag" );
    }
    
    //---------------------------------------------------------------
    void addSettings( ofxSimpleGuiToo & _gui )
    {
        MSAParticleGroup3DMesh::addSettings( _gui );
        _gui.addSlider( "node min", node_min, 1, 10);
        _gui.addSlider( "node max", node_max, 1, 100);
    }
    
    //---------------------------------------------------------------    
    void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3DMesh_PointSprites::setParticleProperties( _p );
        float radius	= ofMap( _p->getMass(), mass_min, mass_max, node_min, node_max );
        _p->setRadius( radius );
        _p->setColor( ofFloatColor(ofRandom(1),ofRandom(1),ofRandom(1), 1) );
        
        point_sizes[group.size()] = radius*2;
        
        ofFloatColor pcol = _p->getColor();
        
        int i=group.size()*3;
        colors[i] = pcol.r; //ofRandom(1);
        colors[i+1] = pcol.g; //ofRandom(1);
        colors[i+2] = pcol.b; //ofRandom(1);
//        colors[i+3] = .1;
        
    }
    
    //---------------------------------------------------------------
    virtual void draw()
    {
        ofEnablePointSprites();
        ofEnableAlphaBlending();
        
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.5);
        
        texture.getTextureReference().bind();
        
        shader.begin();
        
        shader.setUniformTexture("texture", texture, texture.getTextureReference().getTextureData().textureID);
        
        GLint loc = shader.getAttributeLocation( "point_size" );
        GLint color = shader.getAttributeLocation( "col" );
        
        glEnableVertexAttribArray(loc);
        glVertexAttribPointer(loc,1,GL_FLOAT,0,0,point_sizes);
        
        glEnableVertexAttribArray(color);
        glVertexAttribPointer(color,3,GL_FLOAT,0,0,colors);
        
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_POINTS, 0, group.size() );
        
        shader.end();
        
        texture.getTextureReference().unbind();
        
        glDisable(GL_DEPTH_TEST);
        ofDisablePointSprites();
        ofDisableAlphaBlending();
    }
    
};


#endif
