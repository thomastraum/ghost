//
//  MSAFluidManagerApp.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 20/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_MSAFluidManagerApp_h
#define particles_3d_5_MSAFluidManagerApp_h

#pragma once
#include "MSAFluidManager.h"

class MSAFluidManagerApp : public MSAFluidManager {
    
    
    
public:

    void onFadeForceUpAndDown( int _id, float _strength, float _duration )
    {
        forces[_id]->fadeForceUpAndDown( _strength, _duration );
    }
    
};

#endif
