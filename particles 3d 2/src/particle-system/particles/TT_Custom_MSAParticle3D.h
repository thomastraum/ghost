//
//  TT_Custom_MSAParticle3D.h
//  body-impact-1
//
//  Created by Thomas Eberwein on 03/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#pragma once
#include "MSAPhysics3D.h"
//#include "MSACore.h"

using namespace MSA;

class TT_Custom_MSAParticle3D : public Physics::Particle3D {

public:
        
    TT_Custom_MSAParticle3D ()               : Physics::Particle3D() { 
        wrapping_enabled = false;
        color = Color::black();
        constraint=0;
        solvable = false;
    }
    
    TT_Custom_MSAParticle3D ( Vec3f _pos )   : Physics::Particle3D( _pos ) { 
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
		//cout << _pos.x << "  " << _oldPos.x << endl;
		
		//wrap();
        
//        if (is_fadeout_enabled) {
//            alpha*=0.9;
//            if ( alpha <= 0.1 ) {
//                is_fadeout_enabled = false;
//                kill();
//            }
//        }
    }
    
    //----------------------------------------------------------------- COLOR
    TT_Custom_MSAParticle3D * setColor( Color _col )
    {
        color = _col;
        return this;
    }
    
    Color getColor() 
    { 
        return color; 
    }
    
    //----------------------------------------------------------------- ALPHA
    TT_Custom_MSAParticle3D * enableFadeOut( bool _is_fadeout_enabled )
    {
        is_fadeout_enabled = _is_fadeout_enabled;
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
    
    void wrap()
    {
        if(_oldPos.x > _params->worldMax.x ) {
            float vel = _pos.x - _oldPos.x;
            _pos.x = _params->worldMin.x - vel;
            _oldPos.x = _params->worldMin.x ;
            
        } else if ( _oldPos.x < _params->worldMin.x ) {
            float vel = _pos.x - _oldPos.x;
            _pos.x = _params->worldMax.x - vel;
            _oldPos.x = _params->worldMax.x;
        }
        
        if(_oldPos.y > _params->worldMax.y ) {
            float vel = _pos.y - _oldPos.y;
            _pos.y = _params->worldMin.y - vel;
            _oldPos.y = _params->worldMin.y ;
            
        } else if ( _oldPos.x < _params->worldMin.x ) {
            float vel = _pos.y - _oldPos.y;
            _pos.y = _params->worldMax.y - vel;
            _oldPos.y = _params->worldMax.y;
        }
        
//        if(_oldPos.z > _params->worldMax.z ) {
//            float vel = _pos.z - _oldPos.z;
//            _pos.z = _params->worldMin.z - vel;
//            _oldPos.z = _params->worldMin.z ;
//            
//        } else if ( _oldPos.x < _params->worldMin.x ) {
//            float vel = _pos.z - _oldPos.z;
//            _pos.z = _params->worldMax.z - vel;
//            _oldPos.z = _params->worldMax.z;
//        }

    }
    
    
protected:
    
    Physics::Constraint3D * constraint;
    Color                   color;
    float                   alpha;
    bool                    is_fadeout_enabled;    
    bool                    wrapping_enabled;
    bool                    solvable;
    
};
