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

class MSAParticleGroup3D_PointSprites : public MSAParticleGroup3D {
    
    ofMesh      mesh;
    ofImage     texture;
    
    Vec3f     position;    
    
public:
    
    MSAParticleGroup3D_PointSprites() {
        
        mesh.clear();
        mesh.setMode(OF_PRIMITIVE_POINTS);
        
        ofDisableArbTex();
        texture.loadImage("dot-8.png");
        
        glPointSize(2);
        
    }
    
    virtual void setParticleProperties( TT_Custom_MSAParticle3D * _p )
    {
        MSAParticleGroup3D::setParticleProperties( _p );
        
        mesh.addVertex( ofVec3f( _p->getPosition().x, _p->getPosition().y, _p->getPosition().z ) );
        mesh.addColor( _p->getColor() ); //ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)) );
    }
    
    virtual void update() {
        
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        int i=0;
        
        ofLogNotice("TT") << group.size();
        
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            if( p->isDead() ) {
//                mesh.removeVertex(i);
                it = group.erase(it);
            } else {
                position = p->getPosition();
                mesh.setVertex( i, ofVec3f( position.x, position.y, position.z ) );
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
        mesh.draw();
        
        ofDisablePointSprites();
    }
    
};


#endif
