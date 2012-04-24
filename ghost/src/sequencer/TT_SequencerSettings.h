//
//  TT_SequencerSettings.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 21/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_SequencerSettings_h
#define particles_3d_5_TT_SequencerSettings_h

#pragma once
#include "ofxSimpleGuiToo.h"
#include "TT_Sequencer.h" 

class TT_SequencerSettings : public TT_Sequencer {
    
private:
    
    ofxSimpleGuiPage * gui_page;
    
public:
    
    void addSettings( ofxSimpleGuiToo & _gui)
    {
        gui_page = & _gui.addPage( "Sequencer Settings" );
        
        _gui.addSlider( "Prob nice", prob, 0,1 );
        _gui.addSlider( "Prob mean", burstprob, 0,1 );
    }
    
    void setXMLFilename( string _name )
    {
        gui_page->setXMLName( _name );
    }
    
};

#endif
