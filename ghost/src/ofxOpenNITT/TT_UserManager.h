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
#include "TT_User.h"

class TT_UserManager {
    
    vector<TT_User*>    users;
        
public:
    
    TT_UserManager(){
        
        ofAddListener( TT_UserLostEventDispatcher,this,&TT_UserManager::deleteUser );
        ofAddListener( TT_NewUserDispatcher,this,&TT_UserManager::createNewUser );
        
        offset = ofVec3f(0,-100,1000);
        scale = ofVec3f( 1,1,-1 );
    }
    
    //--------------------------------------------------------------
    // Update positions of user joints with the joint particles
    void update() 
    {
        vector<TT_User*>::iterator it = users.begin();
        while( it != users.end() ) {
            TT_User * u = *it;
            u->update();
            it++;
        }
    }
    
    //--------------------------------------------------------------
    // Draw positions of joint particles
    void draw() 
    {   
        vector<TT_User*>::iterator it = users.begin();
        while( it != users.end() ) {
            TT_User * u = *it;
            u->draw();
            it++;
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
                delete * it;  
                it = users.erase(it);
            } else {
                it++;
            }
        }
    }
    
};

#endif
