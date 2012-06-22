//
//  TT_User.h
//  openNi recorder
//
//  Created by Thomas Eberwein on 19/06/2012.
//  Copyright 2012 Thomas Traum Ltd. All rights reserved.
//

#ifndef openNi_recorder_TT_User_h
#define openNi_recorder_TT_User_h

#pragma once
#include "ofxOpenNI.h"
#include "TT_JointParticle.h"
//#include "MSAParticleGroup3D_Fixed.h"
#include "MSAPhysicsUpdaterCollision.h"

class TT_User : public MSAPhysicsUpdaterCollision {
    
    ofxOpenNIUser * niuser;
    XnUserID        id;
    ofMatrix4x4     trans, scale;
    
    vector<TT_JointParticle*> particles;
    
public:
    
    //--------------------------------------------------------------
    TT_User( ofxOpenNIUser * _niuser, XnUserID _id, ofVec3f _scale, ofVec3f _offset ){
        niuser = _niuser;
        id = _id;
        
        scale.makeScaleMatrix( _scale ); //ofVec3f(1,1,-1) );
        trans.makeTranslationMatrix( _offset ); //ofVec3f(0,-100,1000));
        
        initParticles();
    }
    
    //--------------------------------------------------------------
    // delete this user
    ~TT_User(){
        kill();
    }
    
    //--------------------------------------------------------------
    // clean up
    void kill() {
        
        MSAPhysicsUpdaterCollision::kill();
        
        vector<TT_JointParticle*>::iterator it = particles.begin();
        while ( it != particles.end() ) {
//            delete * it;
            TT_JointParticle * p = *it;
            it = particles.erase(it);
            // DO NOT release here. was already released in parent
//          p->release();
        }
        ofLogNotice( "TT-NI" ) << "deleted user " << id;
    }
    
    //--------------------------------------------------------------
    ofVec3f getCenter()
    {
        return translateToAppSpace( niuser->getCenter() );
    }
    
    //--------------------------------------------------------------
    // create collider particles only for the joints we want
    // add those to the parent collider vector array
    void initParticles()
    {
        for(int i = 0; i < niuser->getNumJoints(); i++){
            
            ofxOpenNIJoint & joint = niuser->getJoint((Joint)i);
            
            if ( joint.getType() == JOINT_TORSO ||
                joint.getType() == JOINT_HEAD ||
                joint.getType() == JOINT_LEFT_ELBOW || 
                joint.getType() == JOINT_LEFT_HAND || 
                joint.getType() == JOINT_RIGHT_ELBOW || 
                joint.getType() == JOINT_RIGHT_HAND || 
                joint.getType() == JOINT_LEFT_KNEE || 
                joint.getType() == JOINT_LEFT_FOOT ||
                joint.getType() == JOINT_RIGHT_KNEE ||
                joint.getType() == JOINT_RIGHT_FOOT ) {
                
                TT_JointParticle * p = new TT_JointParticle( Vec3f( 0,0,0 ) );
                particles.push_back(p);
                p->setJointType( joint.getType() );
                
                // adding those to parent class //
                MSAPhysicsUpdaterCollision::addToCollisionCheck( p );
            }
        }
    }
    
    //--------------------------------------------------------------
    // get the right jointtype by looking in the saved joint type property of the particle 
    void updateJointParticle() 
    {
        int i = 0;
        ofPoint point;
        vector<TT_JointParticle*>::iterator it = particles.begin();
        while( it != particles.end() ){
            
            TT_JointParticle * p = *it;
            ofxOpenNIJoint & joint = niuser->getJoint( p->joint_type );
        
            point = translateToAppSpace( joint.getWorldPosition() );
            p->moveTo( Vec3f( point.x, point.y, point.z) );
                
            it++;
        }
        
        MSAPhysicsUpdaterCollision::calculateBoundingBox();
    }
    
    //--------------------------------------------------------------
    // draws them for debug.
    void draw() 
    {
        ofSetColor(255, 0, 255);
        ofCircle( getCenter(), 100 );
        
        Vec3f pos;
        vector<TT_JointParticle*>::iterator it = particles.begin();
        while( it != particles.end() ) {
            TT_JointParticle * p = *it;
            ofSetColor( 255,255,255 );
            pos = p->getPosition();
            ofCircle( pos.x,pos.y, pos.z, p->getRadius()*2 );
            it++;
        }
    }
    
    //--------------------------------------------------------------
    // this brings the points into our coordinate system
    ofVec3f translateToAppSpace( ofVec3f _point )
    {
        ofVec3f newPoint = _point * scale * trans;
        return newPoint; //newPoint;
    }
    
    //--------------------------------------------------------------
    // id is used on deletion of a user, matching the ID in openNI
    XnUserID getID()
    {
        return id;
    }
    
};

#endif


/*
 
 FOR REF
 
 // start at root joint
 JOINT_TORSO = 0,
 JOINT_NECK,
 JOINT_HEAD,
 
 // left arm + shoulder
 JOINT_LEFT_SHOULDER,
 JOINT_LEFT_ELBOW,
 JOINT_LEFT_HAND,
 
 // right arm + shoulder
 JOINT_RIGHT_SHOULDER,
 JOINT_RIGHT_ELBOW,
 JOINT_RIGHT_HAND,
 
 // left leg
 JOINT_LEFT_HIP,
 JOINT_LEFT_KNEE,
 JOINT_LEFT_FOOT,
 
 // right leg
 JOINT_RIGHT_HIP,
 JOINT_RIGHT_KNEE,
 JOINT_RIGHT_FOOT,
 
 JOINT_COUNT,
 JOINT_UNKOWN
 */
