//
//  MSAPhysicsUpdater3D.cpp
//  body-impact-1
//
//  Created by Thomas Eberwein on 03/06/2011.
//  Copyright 2011 --. All rights reserved.
//

#include "MSAPhysicsUpdater3D.h"


void MSAPhysicsUpdater3D::setWindowSize( Vec2f &_windowSize ) 
{
    windowSize = _windowSize;
	invWindowSize = Vec2f( 1.0f / _windowSize.x, 1.0f );
}