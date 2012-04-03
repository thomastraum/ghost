//
//  TT_Sequencer.h
//  particles 3d 5
//
//  Created by Thomas Eberwein on 21/03/2012.
//  Copyright 2012 --. All rights reserved.
//

#ifndef particles_3d_5_TT_Sequencer_h
#define particles_3d_5_TT_Sequencer_h

#pragma once
#include "ofMain.h"
#include "ofEvents.h"
#include "AppEvents.h"
#include "TT_Tempo.h"

//----------------------------------------------------------------------
//----------------------------------------------------------------------

struct ForceEventParameters {
    int     force_id;
    float   strength;
    float   duration;
};

struct LoopEventParameters {
    int     sound_id;
    float   volume;
    float   pan;
    float   duration;
};

struct SoundFxEventParameters {
    int     sound_id;
    float   volume;
    float   pan;
};

struct EmitParticlesEventParameters {
    int     emitter_id;
    float   amount;
};

struct BoxFlashEventParameters {
    ofFloatColor    color;
    float           duration;
};

struct PGravEventParameters {
    float   gravity;
};

//----------------------------------------------------------------------
//----------------------------------------------------------------------

class TT_Sequencer {
    
    //----------------------------------------------------------------------
protected:
    
    TT_Tempo    tempo;
    
    // General probability to be used in child classes
    float prob;
    float burstprob;
    
    // Event Parameters structs
    ForceEventParameters            f_para;
    LoopEventParameters             l_para;
    SoundFxEventParameters          s_para;
    EmitParticlesEventParameters    e_para;
    BoxFlashEventParameters         b_para;
    PGravEventParameters            pgrav_para;
    
    void triggerForceEvent()
    {
        ForceEvent event = ForceEvent( f_para.force_id, f_para.strength, f_para.duration );
        ofNotifyEvent(ForceEventDispatcher, event);
    }
    void triggerLoopEvent()
    {
        LoopEvent event = LoopEvent( l_para.sound_id, l_para.volume, l_para.pan, l_para.duration );
        ofNotifyEvent(LoopEventDispatcher, event);
    }
    void triggerSoundFxEvent()
    {
        SoundFxEvent event = SoundFxEvent( s_para.sound_id, s_para.volume, s_para.pan );
        ofNotifyEvent(SoundFxEventDispatcher, event);
    }
    void triggerEmitParticlesEvent()
    {
        EmitParticlesEvent event = EmitParticlesEvent( e_para.emitter_id, e_para.amount );
        ofNotifyEvent(EmitParticlesEventDispatcher, event);
    }
    void triggerBoxFlashEvent()
    {
        BoxFlashEvent event = BoxFlashEvent( b_para.color, b_para.duration );
        ofNotifyEvent(BoxFlashEventDispatcher, event);
    }
    
    void triggerPGravEvent()
    {
        PGravEvent event = PGravEvent( pgrav_para.gravity );
        ofNotifyEvent(PGravEventDispatcher, event);
    }
    
    //----------------------------------------------------------------------
public:
    
    TT_Sequencer() {
        ofAddListener(tempo.onQuarterNote,this,&TT_Sequencer::onQuarterNote);
        ofAddListener(tempo.onHalfNote,this,&TT_Sequencer::onHalfNote);
        ofAddListener(tempo.onFullNote,this,&TT_Sequencer::onFullNote);
        
        f_para.force_id = 0;
        f_para.strength = 0;
        f_para.duration = 0;
    }
    
    void start()
    {
        tempo.start();
    }
    
    void stop()
    {
        tempo.stop();
    }
    
    void update()
    {
        tempo.update();
    }
    
    //-------------------------------------------------------------------   Virtual Event Listeners
    virtual void onQuarterNote( int &beats ) {}
    
    //-------------------------------------------------------------------
    virtual void onHalfNote( int &beats ) {}
    
    //-------------------------------------------------------------------
    virtual void onFullNote( int &beats ){}
    
};

#endif
