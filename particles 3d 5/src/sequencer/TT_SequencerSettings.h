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
        
        _gui.addSlider( "Probability", prob, 0,1 );
        
        _gui.addTitle( "Force Settings" );
        _gui.addSlider( "Force ID", f_para.force_id,0,3);
        _gui.addSlider( "Force Strength", f_para.strength,0,0.3);
        _gui.addSlider( "Force Duration", f_para.duration,0,5);
        
        _gui.addTitle( "BoxFlash Settings" );
        _gui.addSlider( "BoxFlash Color R", b_para.color.r,0,1);
        _gui.addSlider( "BoxFlash Color G", b_para.color.g,0,1);
        _gui.addSlider( "BoxFlash Color B", b_para.color.b,0,1);
        _gui.addSlider( "BoxFlash Duration", b_para.duration,0,5);
    }
    
    void setXMLFilename( string _name )
    {
        //    xml_filename = _xml_filename;
        gui_page->setXMLName( _name );
    }
    
};

#endif
