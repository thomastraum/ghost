//
//  MSAParticleGroup3DMesh_Quad.h
//  particles 3d 3
//
//  Created by Thomas Eberwein on 16/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "MSAParticleGroup3DMesh.h"

class MSAParticleGroup3DMesh_Quad : public MSAParticleGroup3DMesh {
    
private:
    
    ofImage     texture;
    ofVbo       vbo;
    
    ofColor     color;
    ofVec3f     pos, top, right, bottom, left;
    
public:
    
    MSAParticleGroup3DMesh_Quad() {
        
        color = ofColor(255,255,255 );
        
        mesh.clear();
//        mesh.setMode( OF_PR );
        
        ofDisableArbTex();
        texture.loadImage("dot-8.png");
        
    }
    
    void addParticleToMesh( TT_Custom_MSAParticle3D * _p )
    {
        float radius = _p->getRadius();
        pos =  ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z );
        
        top     = ofVec3f( pos.x-radius, pos.y-radius, pos.z );
        right   = ofVec3f( pos.x+radius, pos.y-radius, pos.z );
        bottom  = ofVec3f( pos.x+radius, pos.y+radius, pos.z );
        left    = ofVec3f( pos.x-radius, pos.y+radius, pos.z );
        
        mesh.addVertex( top );
        mesh.addVertex( right );
        mesh.addVertex( bottom );
        mesh.addVertex( left );
        
        mesh.addTexCoord( ofVec2f( 0,0 ) );
        mesh.addTexCoord( ofVec2f( 1,0 ) );
        mesh.addTexCoord( ofVec2f( 1,1 ) );
        mesh.addTexCoord( ofVec2f( 0,1 ) );
        
        mesh.addColor( color );
        mesh.addColor( color );
        mesh.addColor( color );
        mesh.addColor( color );
    }
    
    void updateIndexWithParticle( TT_Custom_MSAParticle3D * _p, int index )
    {
        float radius = _p->getRadius();
        pos =  ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z );
        
        top     = ofVec3f( pos.x-radius, pos.y-radius, pos.z );
        right   = ofVec3f( pos.x+radius, pos.y-radius, pos.z );
        bottom  = ofVec3f( pos.x+radius, pos.y+radius, pos.z );
        left    = ofVec3f( pos.x-radius, pos.y+radius, pos.z );
        
        int i = index * 4;
        mesh.setVertex( i++, top );
        mesh.setVertex( i++, right );
        mesh.setVertex( i++, bottom );
        mesh.setVertex( i++, left );
    }
    
    void draw()
    {
        ofEnableAlphaBlending();
        
        //        OF_BLENDMODE_DISABLED = 0,
        //        OF_BLENDMODE_ALPHA 	  = 1,
        //        OF_BLENDMODE_ADD 	  = 2,
        //        OF_BLENDMODE_SUBTRACT = 3,
        //        OF_BLENDMODE_MULTIPLY = 4,
        //        OF_BLENDMODE_SCREEN   = 5
        //        ofEnableBlendMode( OF_BLENDMODE_ADD );
        
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.1);
        
        texture.getTextureReference().bind();
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_QUADS, 0, mesh.getNumVertices() );
        texture.getTextureReference().unbind();		// new in OF006
        
        glDisable(GL_ALPHA_TEST);
        glDisable(GL_DEPTH_TEST);
        
        ofDisableAlphaBlending();
    }
    
    
};