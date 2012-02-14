//
//  MSAParticleGroup3D_PointSprites.h
//  particles 3d 2
//
//  Created by Thomas Eberwein on 07/02/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_2_MSAParticleGroup3D_PointSprites_h
#define particles_3d_2_MSAParticleGroup3D_PointSprites_h

#pragma once
#include "ofMain.h"
#include "MSAParticleGroup3D.h"

class MSAParticleGroup3D_PointSpritesVBO : public MSAParticleGroup3D {
    
    ofMesh      mesh;
    ofImage     texture;
    ofVbo       vbo;
    
public:
    
    MSAParticleGroup3D_PointSpritesVBO() {
        
        mesh.clear();
        mesh.setMode( OF_PRIMITIVE_POINTS );
        
        ofDisableArbTex();
        texture.loadImage("dot-8.png");
        
        glPointSize(10);
    }
    
    virtual void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3D::setParticleProperties( _p );
        _p->setRadius(10);
        _p->setVelocity( Vec3f(200,0,0) );
        mesh.addVertex( ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
        mesh.addColor( ofColor( 0, 255, 255 ) ); //ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)) );
    }
    
    virtual void update() {
        
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            if( p->isDead() ) {
                cout << "killed" << endl;
                it = group.erase(it);
            } else {
                mesh.setVertex( i, ofVec3f( p->getPosition().x, p->getPosition().y, p->getPosition().z ) );
                i++;
                it++;
            }
        }
    };
    
    virtual void draw()
    {
        ofEnableAlphaBlending();
        ofEnablePointSprites();
        
        texture.getTextureReference().bind();
        vbo.setMesh( mesh, GL_STATIC_DRAW );
        vbo.draw( GL_POINTS, 0, mesh.getNumVertices() );
        texture.getTextureReference().unbind();		// new in OF006
        
        ofDisablePointSprites();
    }
    
    virtual void resizeParticleGroup()
    {
        MSAParticleGroup3D::resizeParticleGroup();
        mesh.clearVertices();
    }
};


#endif
