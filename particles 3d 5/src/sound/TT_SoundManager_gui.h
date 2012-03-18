//
//  TT_SoundManager_gui.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 17/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_SoundManager_gui_h
#define particles_3d_5_TT_SoundManager_gui_h

#pragma once
#include "TT_SoundManager.h"
#include "ofxSimpleGuiToo.h"

class TT_SoundManager_gui : public TT_SoundManager {
    
private:
    
    float gui_volume, gui_pan;
    
public:
    
    void update()
    {
        TT_SoundManager::update();

        gui_volume = sound.getVolume();
        gui_pan = sound.getPan();
    }
    
    
    void addSettings( ofxSimpleGuiToo & _gui)
    {
        _gui.addPage( "sound page" );
        _gui.addTitle( "Sound Settings" );
        _gui.addSlider( "volume", gui_volume, 0,1 );
        _gui.addSlider( "pan", gui_pan, 0,1 );
    }
    
    
};


#endif
