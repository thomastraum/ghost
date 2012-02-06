//
//  TT_Custom_MSAParticle.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 03/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once
#include "MSAPhysics3D.h"
//#include "MSACore.h"

using namespace MSA;

class TT_Custom_MSAParticle : public Physics::Particle3D {

public:
        
    TT_Custom_MSAParticle ()               : Physics::Particle3D() { 
        wrapping_enabled = false;
        color = Color::black();
        constraint=0;
        solvable = false;
    }
    
    TT_Custom_MSAParticle ( Vec3f _pos )   : Physics::Particle3D( _pos ) { 
        wrapping_enabled = false;
        color = Color::black();
        constraint=0;
        solvable = false;
    }
    
	void collidedWithEdgeOfWorld(Vec3f collisionForce) 
	{
        if( wrapping_enabled ) {
            wrap();
        }
	}
	
    void update()
    {
//        if (is_fadeout_enabled) {
//            alpha*=0.9;
//            if ( alpha <= 0.1 ) {
//                is_fadeout_enabled = false;
//                kill();
//            }
//        }
    }
    
    //----------------------------------------------------------------- COLOR
    TT_Custom_MSAParticle * setColor( Color _col )
    {
        color = _col;
        return this;
    }
    
    Color getColor() 
    { 
        return color; 
    }
    
    //----------------------------------------------------------------- ALPHA
    TT_Custom_MSAParticle * enableFadeOut( bool _is_fadeout_enabled )
    {
        is_fadeout_enabled = _is_fadeout_enabled;
        return this;
    }
    
    TT_Custom_MSAParticle * setAlpha( float _alpha )
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
    
    TT_Custom_MSAParticle * setWrap( bool _wrap_x, bool _wrap_y )
    {
        wrapping_enabled = ( _wrap_x || _wrap_y ) ? true : false;
    }
    
    void wrap()
    {
//        cout << "_params->worldMax.x " << _params->worldMax.x << endl;
//        cout << "_params->worldMin.x " << _params->worldMin.x << endl;
//        cout << "_radius " << _radius << endl;
        
        if(_oldPos.x < _params->worldMin.x + _radius ) {
            float vel = _pos.x - _oldPos.x;
            _pos.x = _params->worldMax.x - _radius;
            _oldPos.x =  _pos.x + vel;
        } else if(_oldPos.x > _params->worldMax.x - _radius) {
            float vel = _pos.x - _oldPos.x;
            _pos.x = _params->worldMin.x + _radius;
            _oldPos.x =  _pos.x - vel;
        }
        
        if( _oldPos.y < _params->worldMin.y + _radius) {
            float vel = _pos.y - _oldPos.y;
            _pos.y = _params->worldMax.y - _radius;
            _oldPos.y = _pos.y + vel;
        } else if(_oldPos.y > _params->worldMax.y - _radius) {
            float vel = _pos.y - _oldPos.y;
            _pos.y = _params->worldMin.y + _radius;
            _oldPos.y =  _pos.y - vel;
        }
    }
    
    
protected:
    
    Physics::Constraint3D * constraint;
    Color                   color;
    float                   alpha;
    bool                    is_fadeout_enabled;    
    bool                    wrapping_enabled;
    bool                    solvable;
    
};
