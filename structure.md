
**priorities**
gravity event
sound fx event
emitt particles
random pos force
fog flashing
Monolake north
fluxion prospect one



**Quiet**
 
> onQuarterNote 
>> a random slow force event
>> a soft Box blink
>> a soft fog fade
  	
> onFullNote
>> loopchange
>> soft grav change
 >> camera move

makeAPush
	force
	random force sound
	blink
	


-------------------------------

AppEvents
	sound
	forceEvent
	particle

-------------------------------
Force
	fadeForce
	fadeForceUpAndDown

ForceManager
	onFadeForceUpAndDown _id, _strength, _duration 

-------------------------------
Tempo
Sequencer 
> onQuarterNote
>> if ( random(0,1) < prob ) 
>>> forceEvent( type, strength, duration )
>>> boxEvent( type, color, _duration )

 

