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
    
    TT_JointParticle ( Vec3f _pos ) : TT_Custom_MSAParticle3D( _pos ) {}
    
    Joint joint_type;
    
};


#endif
