//
//  TT_Presets.h
//  particles 3d 4
//
//  Created by Thomas Eberwein on 17/02/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

struct Preset {
    string preset_name;
};

class TT_Presets {
    
    vector<Preset * > presets;
    int preset_counter;
    
public:
    
    TT_Presets()
    {
        Preset * preset_1 = new Preset();
        preset_1->preset_name = "quiet/";
        presets.push_back(preset_1);
        
        Preset * preset_2 = new Preset();
        preset_2->preset_name = "stormy/";
        presets.push_back(preset_2);
        
        preset_counter = 0;
    }
    
    string getNextPresetName()
    {
        int next_index = preset_counter%presets.size();
        preset_counter++;
        
        return presets[ next_index ]->preset_name;
    }
    
    
};



//vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
//
//while( it != group.end() ) {
//    TT_Custom_MSAParticle3D * p = *it;
//    if( p->isDead() ) {
//        it = group.erase(it);
//    } else {
//        ofPushStyle();
//        ofFill();
//        ofSetHexColor( particle_default_color );
//        ofCircle( p->getPosition().x, p->getPosition().y, p->getPosition().z, p->getRadius() );
//        ofPopStyle();
//        it++;
//    }
//}
