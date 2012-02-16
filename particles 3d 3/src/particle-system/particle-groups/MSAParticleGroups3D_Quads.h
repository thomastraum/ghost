//
//  MSAParticleGroups3D_Quads.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 15/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

//
//  MSAParticleGroup3D_PointSprites.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 07/02/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_2_MSAParticleGroups3D_Quads
#define particles_3d_2_MSAParticleGroups3D_Quads

#pragma once
#include "ofMain.h"
#include "MSAParticleGroup3D.h"

class MSAParticleGroups3D_Quads : public MSAParticleGroup3D {
    
    ofMesh      mesh;
    ofImage     texture;
    ofVbo       vbo;
    
    ofColor     color;
    ofVec3f     pos, top, right, bottom, left;
    
    
public:
    
    MSAParticleGroups3D_Quads() {
        
        color = ofColor(255,255,255 );
        
        mesh.clear();
        mesh.setMode( OF_PRIMITIVE_POINTS );
        
        ofDisableArbTex();
        texture.loadImage("dot-8.png");
    }
    
    virtual void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3D::setParticleProperties( _p );
        addQuadForParticle( _p );
    }
    
    void addQuadForParticle( TT_Custom_MSAParticle3D * _p )
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
    
    virtual void update() {
        
        MSAParticleGroup3D::update();

        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            
            float radius = p->getRadius();
            pos =  ofVec3f( p->getPosition().x, p->getPosition().y, p->getPosition().z );
            
            top     = ofVec3f( pos.x-radius, pos.y-radius, pos.z );
            right   = ofVec3f( pos.x+radius, pos.y-radius, pos.z );
            bottom  = ofVec3f( pos.x+radius, pos.y+radius, pos.z );
            left    = ofVec3f( pos.x-radius, pos.y+radius, pos.z );
            
            mesh.setVertex( i++, top );
            mesh.setVertex( i++, right );
            mesh.setVertex( i++, bottom );
            mesh.setVertex( i++, left );
            
            it++;
        }
    };
    
    virtual void draw()
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
    
    virtual void resizeParticleGroup()
    {
        MSAParticleGroup3D::resizeParticleGroup();
        mesh.clear();
        
        //
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            addQuadForParticle( p );
            it++;
        }
        
    
    }
};


#endif
