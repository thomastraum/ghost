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
#include "MSAParticleGroup3D.h"

class MSAParticleGroup3DPointSprites : public MSAParticleGroup3D {
    
    
    MSAParticleGroup3DPointSprites() {}
    
    ofMesh mesh;
    
public:
    
    virtual void draw() {
        
        vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
        
        while( it != group.end() ) {
            TT_Custom_MSAParticle3D * p = *it;
            if( p->isDead() ) {
                it = group.erase(it);
            } else {
//                ofPushStyle();
//                ofFill();
//                ofSetHexColor( particle_default_color );
//                ofCircle( p->getPosition().x, p->getPosition().y, p->getPosition().z, p->getRadius() );
//                ofPopStyle();
                it++;
            }
        }
    };
    
};


#endif
