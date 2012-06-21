//
//  TT_Custom_MSAParticle3D.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 03/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once
#include "MSAPhysics3D.h"

using namespace MSA;

class TT_Custom_MSAParticle3D : public Physics::Particle3D {

protected:
    
    Physics::Constraint3D * constraint;
    ofFloatColor            color;
    float                   alpha;
    bool                    is_fadeout_enabled;    
    bool                    wrapping_enabled;
    bool                    solvable;
    
    //----------------------------------------------------------------- LONG LINES
    void enableSavePosition()
    {
        save_position = true;
    }
    
    
public:
    
    vector<Vec3f>           pos;
    int                     pos_length;
    bool                    save_position;
    
    TT_Custom_MSAParticle3D ( Vec3f _pos )   : Physics::Particle3D( _pos ) { 
        wrapping_enabled = false;
        is_fadeout_enabled = false;
        color = ofFloatColor::white;
        constraint=0;
        solvable = false;
        alpha = 1.0;
        save_position = false;
    }
    
    void update()
    {
        // fade out a bit (and kill if alpha == 0);
        if (is_fadeout_enabled) {
            alpha *= 0.99f;
            if( alpha < 0.1f ) {
                kill();
            }
        }
        
        if ( save_position ) {
            for( int i=pos_length-1; i>0; i-- ){
                pos[i] = pos[i-1];
            }
//            pos[1] = pos[0] - (getVelocity()*2);
            pos[0] = getPosition();
        }
        
    }
    
    //----------------------------------------------------------------- LONG LINES
    void setNumberOfSavedPositions( int _num )
    {
        for( int i=0; i<_num; i++ ){
            pos.push_back( getPosition() );
        }
        pos_length = _num;
        enableSavePosition();
    }

    //----------------------------------------------------------------- COLOR
    TT_Custom_MSAParticle3D * setColor( ofFloatColor _col )
    {
        color = _col;
        return this;
    }
    
    ofFloatColor getColor() 
    { 
        return color; 
    }
    
    //----------------------------------------------------------------- ALPHA
    TT_Custom_MSAParticle3D * enableFadeOut()
    {
        is_fadeout_enabled = true;
        return this;
    }
    
    TT_Custom_MSAParticle3D * setAlpha( float _alpha )
    {
        alpha = _alpha;
        return this;
    }
    
    float getAlpha( )
    {
        return alpha;
    }
    
    //----------------------------------------------------------------- CONSTRAINT 
    void setConstraint( Physics::Constraint3D * _constraint )
    {
        constraint = _constraint;
    }
    
    Physics::Constraint3D * getConstraint()
    {
        return constraint;
    }
    
    bool hasConstraint()
    {
        
//        return ((constraint==0) ? false : true);
    }
    
    void setSolvable( bool _val )
    {
        solvable = _val;
    }
    
    bool isSolvable()
    {
        return solvable;
    }
    
    //----------------------------------------------------------------- WRAPPING
    
    TT_Custom_MSAParticle3D * setWrap( bool _wrap_x, bool _wrap_y )
    {
        wrapping_enabled = ( _wrap_x || _wrap_y ) ? true : false;
    }
    
    void checkWorldEdges()
    {
        if( wrapping_enabled ) {
            wrap();
        } else {
            Physics::Particle3D::checkWorldEdges();
        }
    }
    
    void wrap()
    {
        
        bool collided = false;
        Vec3f oldVel = getVelocity();
        
        // TT wrapping
        for(int i=0; i<3; i++) {
            
            float vel = _pos[i] - _oldPos[i];
            if(_pos[i] < _params->worldMin[i] + _radius) {
                _oldPos[i] = _params->worldMax[i] - _radius;
                _pos[i] = _oldPos[i] + vel * _bounce;
                collided = true;
            } else if(_pos[i] > _params->worldMax[i] - _radius) {
                _oldPos[i] = _params->worldMin[i] + _radius;
                _pos[i] = _oldPos[i] + vel * _bounce;
                collided = true;
            }
        }
        
    }
    
    void collidedWithEdgeOfWorld(Vec3f collisionForce) {}
	
    void collidedWithParticle(Physics::Particle3D *other, Vec3f collisionForce)
    {
//        setColor( ofFloatColor( 1,0,0 ) );
//        setRadius( 100 );
        
    }
};
