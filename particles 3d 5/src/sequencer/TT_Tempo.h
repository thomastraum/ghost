//
//  Tempo.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 20/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_Tempo_h
#define particles_3d_5_Tempo_h

#pragma once
#include "MSATimer.h"

class TT_Tempo {
    
    int         BPM;
    int         time_signature; // = TIME_SIGNATURE;
    int         measure; // = MEASURE;
    int         half_measure;
    
    int         beats;
    float       beat_second;
    MSA::Timer  timer;
    
public:

    TT_Tempo() {
        
        BPM = 50;
        measure = 4;
        half_measure = measure/2;
        
        beats = 0;
        beat_second = (float)60/BPM;
    }
    
    ofEvent<int> onQuarterNote;
    ofEvent<int> onHalfNote;
    ofEvent<int> onFullNote;
    
    //---------------------------------------------------------------
    void start()
    {
        timer.start();
    }
    
    //---------------------------------------------------------------
    void stop()
    {
        timer.stop();
        beats = 0;
    }
    
    void setBPM( int _BPM )
    {
        BPM = _BPM;
        beat_second = (float)60/BPM;
    }
    
    //---------------------------------------------------------------
    void update(){
        
        if( timer.getSeconds() / beat_second > beats ) {
            
            beats++;
            quarterNote();
            
            if ( beats % half_measure == 0 )
                halfNote();
            
            if ( beats % measure == 0 )
                fullNote();
            
        }

    };
    
    //---------------------------------------------------------------
    void quarterNote() 
    {
//        cout << "quarterNote: " << endl;
        ofNotifyEvent(onQuarterNote, beats);
    };
    
    //---------------------------------------------------------------
	void halfNote()
    {
//        cout << "-- halfNote" << endl;
        ofNotifyEvent(onHalfNote, beats);
    };
    
    //---------------------------------------------------------------
	void fullNote()
    {
//        cout << "---- fullNote" << endl;
        ofNotifyEvent(onFullNote, beats);
    }; 
    
    
};


#endif
