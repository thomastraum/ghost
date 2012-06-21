//
//  TT_UserManager.h
//  openNi recorder
//
//  Created by Thomas Eberwein on 19/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef openNi_recorder_TT_UserManager_h
#define openNi_recorder_TT_UserManager_h

#pragma once
#include "ofxOpenNI.h"
#include "TT_PlayerEvents.h"
#include "AppEvents.h"
#include "TT_User.h"

class TT_UserManager {
    
    vector<TT_User*>    users;
    bool                draw_debug;
        
public:
    
    TT_UserManager(){
        
        // user events from the player
        ofAddListener( TT_UserLostEventDispatcher,this,&TT_UserManager::deleteUser );
        ofAddListener( TT_NewUserDispatcher,this,&TT_UserManager::createNewUser );
        
        // key and exit events
//	    ofAddListener(ofEvents().exit, this, &TT_UserManager::exit);
	    ofAddListener(ofEvents().keyPressed, this, &TT_UserManager::keyPressed);
        
        offset = ofVec3f(0,-100,1000);
        scale = ofVec3f( 1,1,-1 );
        
        draw_debug = false;
    }
    
    //--------------------------------------------------------------
    // Update positions of user joints with the joint particles
    void update() 
    {
        vector<TT_User*>::iterator it = users.begin();
        while( it != users.end() ) {
            TT_User * u = *it;
            u->updateJointParticle();
            it++;
        }
    }
    
    //--------------------------------------------------------------
    // Draw positions of joint particles
    void draw() 
    {   
        if( draw_debug ) {
            vector<TT_User*>::iterator it = users.begin();
            while( it != users.end() ) {
                TT_User * u = *it;
                u->draw();
                it++;
            }
        }
    }
    
protected:
    
    ofVec3f scale;
    ofVec3f offset;
    
    //--------------------------------------------------------------
    void createNewUser( TT_NewUserEvent & event ) 
    {
        ofLogNotice("TT-NI") << "TT_UserManager::createNewUser ---------------------------- ";
        ofLogNotice("TT-NI") << event.user->getDebugInfo();
        
        // Sometimes we can get a new user event twice for the same user //
        deleteUser( event.id );
        
        TT_User * user = new TT_User( event.user, event.id, scale, offset );
        users.push_back( user );
        
        AddUpdaterEvent new_user_collision_updater = AddUpdaterEvent( user );
        ofNotifyEvent(AddUpdaterEventDispatcher, new_user_collision_updater);
    }
    
    //--------------------------------------------------------------
    void deleteUser( TT_UserLostEvent & event )
    {
        ofLogNotice("TT-NI") << "TT_UserManager::deleteUser ---------------------------- ";
        ofLogNotice("TT-NI") << event.user->getDebugInfo();
        
        deleteUser( event.id );
    }
    
    //--------------------------------------------------------------
    void deleteUser( int _id )
    {
        vector<TT_User*>::iterator it = users.begin();
        while( it != users.end() ) {
            TT_User * u = *it;
            if( u->getID() == _id ) {
                
//                RemoveUpdaterEvent remove_updaterevent = RemoveUpdaterEvent( u );
//                ofNotifyEvent(RemoveUpdaterEventDispatcher, remove_updaterevent);
            
                it = users.erase(it);
                u->release();
                
            } else {
                it++;
            }
        }
    }
    
    //--------------------------------------------------------------
    void keyPressed( ofKeyEventArgs & arg )
    {
        switch (arg.key) {
            case 'd':
                draw_debug = !draw_debug;
                break;
                
            default:
                break;
        }
    }
    
};

#endif
