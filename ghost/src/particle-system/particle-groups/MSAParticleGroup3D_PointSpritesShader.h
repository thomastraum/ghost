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
    
    vector<float> point_sizes;
    vector<float> colors;

public:
    
    MSAParticleGroup3D_PointSpritesShader() {
        
        shader.load( "shaders/pointsprites.vert", "shaders/pointsprites.frag" );
    }
    
    //---------------------------------------------------------------
    void addSettings( ofxSimpleGuiToo & _gui )
    {
        MSAParticleGroup3DMesh::addSettings( _gui );
        _gui.addSlider( instance_name + " node min", node_min, 1, 10);
        _gui.addSlider( instance_name + " node max", node_max, 1, 100);
    }
    
    //---------------------------------------------------------------    
    void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3DMesh_PointSprites::setParticleProperties( _p );
        
        float radius	= ofMap( _p->getMass(), mass_min, mass_max, node_min, node_max );
        _p->setRadius( radius );
        
        point_sizes.push_back( radius*2 );
        
        ofFloatColor pcol = _p->getColor();
        colors.push_back(pcol.r);
        colors.push_back(pcol.g);
        colors.push_back(pcol.b);
        
    }
    
    //--------------------------------------------------------------- 
    virtual void deleteInMesh( int _index )
    {
        // delete index on mesh
        MSAParticleGroup3DMesh_PointSprites::deleteInMesh(_index);
        
        // delete point size
        point_sizes.erase(point_sizes.begin()+_index);
        
        // delete color
        colors.erase( colors.begin() + (_index*3) );
        colors.erase( colors.begin() + (_index*3) );
        colors.erase( colors.begin() + (_index*3) );
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
        
        shader.setUniformTexture( "texture", texture, texture.getTextureReference().getTextureData().textureID );
        
        GLint loc = shader.getAttributeLocation( "point_size" );
        GLint color = shader.getAttributeLocation( "col" );
        
        glEnableVertexAttribArray(loc);
        glVertexAttribPointer( loc,1,GL_FLOAT,0,0,point_sizes.data() );
        
        glEnableVertexAttribArray(color);
        glVertexAttribPointer( color,3,GL_FLOAT,0,0,colors.data() );
        
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_POINTS, 0, mesh.getNumVertices() ); //group.size() );
        
        shader.end();
        
        texture.getTextureReference().unbind();
        
        glDisable(GL_DEPTH_TEST);
        ofDisablePointSprites();
        ofDisableAlphaBlending();
    }
    
};


#endif
