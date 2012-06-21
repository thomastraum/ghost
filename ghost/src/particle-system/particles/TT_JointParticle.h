//
//  TT_JointParticle.h
//  ghost
//
//  Created by Thomas Eberwein on 20/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_TT_JointParticle_h
#define ghost_TT_JointParticle_h

#include "TT_Custom_MSAParticle3D.h"
#include "ofxOpenNITypes.h"

class TT_JointParticle : public TT_Custom_MSAParticle3D {
    
    
public:
    
    TT_JointParticle ( Vec3f _pos ) : TT_Custom_MSAParticle3D( _pos ) {
    
        makeFixed();
    }
    
    Joint joint_type;
    
    void setJointType( Joint _joint_type )
    {
        joint_type = _joint_type;
        matchJointToRadius();
    }
    
    
    void matchJointToRadius()
    {
        int base_size = 100;
        int mid_size = 120;
        int big_size = 200;
        
        switch ( joint_type ) {
                
            case JOINT_TORSO:
                _radius = base_size;
                break;
            case JOINT_HEAD:
                _radius = base_size;
                break;
            case JOINT_LEFT_ELBOW:
                _radius = mid_size;
                break;
            case JOINT_LEFT_HAND:
                _radius = mid_size;
                break;
            case JOINT_RIGHT_ELBOW:
                _radius = mid_size;
                break;
            case JOINT_RIGHT_HAND:
                _radius = mid_size;
                break;
            case JOINT_LEFT_KNEE:
                _radius = big_size;
                break;
            case JOINT_LEFT_FOOT:
                _radius = big_size;
                break;
            case JOINT_RIGHT_KNEE:
                _radius = big_size;
                break;
            case JOINT_RIGHT_FOOT:
                _radius = big_size;
                break;
            default:
                break;
        }
    }
    
};


#endif
