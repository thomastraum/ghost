# Presets Player

## Sound Scape
	Loops
		start / stop all loops
		change volume on a loop
	Event Sounds
		Event Sound
			load event sounds
			play event sound
	

## mypreset
	Sound
		loop-path
		volume
		eventsound(s)
	Forces
		active forces
	

----------------------------------------------------------
----------------------------------------------------------
# Settings
there are things which are set and there are things which need to be dynamic. Try to set the dynamic ones through pobability setting

----------------------------------------------------------
----------------------------------------------------------
# Scenario

## Start
- load preset		
	- setup soundscape
		load loops  
		load event sounds
		set volume for loops

## Idle state
- alternate between presets over time
	
## Active state (with users)

### generally
- storms happen more often
- soundscape 
	stormy louder
	stormy coming through more often

### User steps in
- Play event sound
- Background flashes
- Particles get emitted 
- switch state

### User dies
- Play event sound
- if no users left
	switch to idle

----------------------------------------------------------
----------------------------------------------------------

# Background
- fade to colour
- flash up

# Forces
- gust of wind