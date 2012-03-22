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
#include "AppEvents.h"

class MSAFluidManagerApp : public MSAFluidManager {
    
public:

    MSAFluidManagerApp(){
        ofAddListener( ForceEventDispatcher,this,&MSAFluidManagerApp::onForceEvent );
    }
    
    void onForceEvent( ForceEvent &args )
    {
        cout << "MSAFluidManagerApp::ForceEvent " << args.force_id << " " << args.strength << " " << args.duration << endl;
        onFadeForceUpAndDown( args.force_id, args.strength , args.duration );
    }
    
    void onFadeForceUpAndDown( int _id, float _strength, float _duration )
    {
        if ( _id >= forces.size() ) {
            ofLogError() << "onFadeForceUpAndDown _id " << _id << " does not exist";
        } else {
            forces[_id]->fadeForceUpAndDown( _strength, _duration );
        }
    }
    
};

#endif
