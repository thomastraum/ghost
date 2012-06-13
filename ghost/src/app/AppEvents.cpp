//
//  AppEvents.cpp
//  particles 3d 5
//
//  Created by Thomas Eberwein on 21/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#include <iostream>
#include "AppEvents.h"

ofEvent<ForceEvent>             ForceEventDispatcher;
ofEvent<LoopEvent>              LoopEventDispatcher;
ofEvent<SoundFxEvent>           SoundFxEventDispatcher;
ofEvent<EmitParticlesEvent>     EmitParticlesEventDispatcher;
ofEvent<BoxFlashEvent>          BoxFlashEventDispatcher;
ofEvent<FogFlashEvent>          FogFlashEventDispatcher;
ofEvent<PGravEvent>             PGravEventDispatcher;
ofEvent<CamTargetAnimateEvent>  CamTargetAnimateEventDispatcher;
ofEvent<CollisionEvent>         CollisionEventDispatcher;

