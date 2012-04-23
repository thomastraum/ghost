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
    
public:
    
    virtual void customDraw()
    {
        ofSetColor( 255, 255, 0 );
        ofBox( 0,0,0, 50 );
    }
    
    
};


#endif
