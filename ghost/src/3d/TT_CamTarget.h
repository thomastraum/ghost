//
//  TT_CamTarget.h
//  ghost
//
//  Created by Thomas Eberwein on 23/04/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef ghost_TT_CamTarget_h
#define ghost_TT_CamTarget_h

#pragma once
#import "ofNode.h"

class TT_CamTarget : public ofNode {
    
    bool draw_debug;
    
public:
    
    TT_CamTarget(){
        draw_debug = false;
        ofAddListener( ofEvents().keyPressed, this, &TT_CamTarget::keyPressedEvent );
    }
    
    virtual void customDraw()
    {
        if ( draw_debug ) {
            ofSetColor( 255, 255, 0 );
            ofBox( 0,0,0, 50 );
        }
    }
    
    void keyPressedEvent( ofKeyEventArgs & args )
    {
        switch (args.key) {
            case 'd':
                draw_debug = !draw_debug;
                break;
        }
    }
    
};


#endif
