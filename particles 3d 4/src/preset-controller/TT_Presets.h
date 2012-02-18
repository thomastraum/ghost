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
        
        Preset * preset_3 = new Preset();
        preset_3->preset_name = "stormy-2/";
        presets.push_back(preset_3);

        preset_counter = 0;
    }
    
    string getNextPresetName()
    {
        int next_index = preset_counter%presets.size();
        preset_counter++;
        
        return presets[ next_index ]->preset_name;
    }
    
    
};