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
        addNewPreset( "quiet" );
        addNewPreset( "stormy" );
        addNewPreset( "stormy-2" );
        
        preset_counter = 0;
    }
    
    void addNewPreset( string _name )
    {
        Preset * preset = new Preset();
        preset->preset_name = _name + "/";
        presets.push_back(preset);
    }
    
    string getNextPresetName()
    {
        int next_index = preset_counter%presets.size();
        preset_counter++;
        
        return presets[ next_index ]->preset_name;
    }
    
    
};