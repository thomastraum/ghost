//
//  TT_UserEvents.cpp
//  ghost
//
//  Created by Thomas Eberwein on 21/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#include "TT_UserEvents.h"

ofEvent<TT_NewJointParticleEvent>       TT_NewJointParticleEventDispatcher;
ofEvent<TT_RemoveJointParticleEvent>    TT_RemoveJointParticleEventDispatcher;