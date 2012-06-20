//
//  TT_UserManagerGui.h
//  ghost
//
//  Created by Thomas Eberwein on 21/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_TT_UserManagerGui_h
#define ghost_TT_UserManagerGui_h

#pragma once
#include "TT_UserManager.h"
#include "ofxSimpleGuiToo.h"

class TT_UserManagerGui : public TT_UserManager {
    
public:
    
    void addSettings( ofxSimpleGuiToo & _gui )
    {
        _gui.addTitle( "User Settings" );
        _gui.addSlider( "User offset Y", offset.y,-1000,1000 );
        _gui.addSlider( "User offset Z", offset.z,500,2000 );
    }
    
};



#endif
