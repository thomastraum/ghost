//
//  TT_DiscoBoxApp.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 22/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_DiscoBoxApp_h
#define particles_3d_5_TT_DiscoBoxApp_h

#include "AppEvents.h"
#include "TT_DiscoBox.h"

class TT_DiscoBoxApp : public TT_DiscoBox {
    
public:
    
    TT_DiscoBoxApp() {
        
        ofAddListener( BoxFlashEventDispatcher,this,&TT_DiscoBoxApp::onBoxFlashEvent );
    }

    void onBoxFlashEvent( BoxFlashEvent & args )
    {
        cout << "TT_DiscoBoxApp::onBoxFlashEvent " << endl;
        flashUp( args.color, args.duration );
    }
};

#endif
