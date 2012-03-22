
#include "MSAParticleSystem3D_Abstract.h"

#define GRAVITY         -0.1
#define SECTOR_COUNT    1

void MSAParticleSystem3D_Abstract::setup()
{
	width           = ofGetWidth();
	height          = ofGetHeight();
    
	ofAddListener(ofEvents.windowResized, this, &MSAParticleSystem3D_Abstract::windowResized);
    
    initScene();
    
}

// ----------------------------------------------------- 
void MSAParticleSystem3D_Abstract::initScene()   
{
    physics.clear();
    addMouseParticle();
    createParticleGroups();

    physics.verbose = false;			// dump activity to log
    gravity = GRAVITY;
    prev_gravity = gravity;
    physics.setGravity(Vec3f(0, gravity, 0) );

    physics.setDrag(0.97f);
    physics.setDrag(1);		// FIXTHIS
    physics.disableCollision(); //enableCollision();
    
}

// ----------------------------------------------------- 
void MSAParticleSystem3D_Abstract::resizeScene()
{
    // set world dimensions, not essential, but speeds up collision
    int offset = 0; //260;
	physics.setWorldSize(Vec3f(-offset-width, -offset-height, -width), Vec3f(offset+width, offset+height, width));
	physics.setSectorCount(SECTOR_COUNT);
}

// ----------------------------------------------------- 
void MSAParticleSystem3D_Abstract::createParticleGroups()
{
    defaultgroup = new MSAParticleGroup3DMesh_Quad();
    defaultgroup->setup();
    groups.push_back(defaultgroup);
}

// ----------------------------------------------------- LOOPS 
void MSAParticleSystem3D_Abstract::update()
{
    if ( prev_gravity != gravity ) {
        prev_gravity = gravity;
        physics.setGravity( gravity );
    }
    
	physics.update();
    
    for (int i=0; i<groups.size(); i++) {
        groups[i]->update(); 
    }
    
    // we show this number in the UI //
    numberOfParticles = physics.numberOfParticles();
}

// ----------------------------------------------------- DRAW
void MSAParticleSystem3D_Abstract::draw()
{
//    defaultgroup->draw();
    for (int i=0; i<groups.size(); i++) {
        groups[i]->draw(); 
    }
    
    // draw mouse //
    ofPushStyle();
    ofFill();
    ofSetColor( 255,0,255 );
    ofCircle( mouse_node.getPosition().x, mouse_node.getPosition().y, mouse_node.getPosition().z, mouse_node.getRadius() );
    ofPopStyle();
}

// ----------------------------------------------------- PUBLIC
void MSAParticleSystem3D_Abstract::addUpdater( Physics::ParticleUpdater3D * _updater )
{
    physics.addUpdater(_updater);
}

// ----------------------------------------------------- 
void MSAParticleSystem3D_Abstract::killAll()
{
    for (int i=0; i<groups.size(); i++) {
        groups[i]->killParticles(); 
    }
}

//------------------------------------------------------ EVENTS
void MSAParticleSystem3D_Abstract::windowResized( ofResizeEventArgs&args )
{
    width = args.width;
    height = args.height;
    resizeScene();
}

// -----------------------------------------------------  PARTICLES
void MSAParticleSystem3D_Abstract::addParticles( Vec3f _pos, int _count )
{
    int max_x = width;
    int max_y = height;
    
    for(int i=0; i<_count; i++)
        addParticle( Vec3f( _pos.x + ofRandom(-max_x, max_x), _pos.y + ofRandom(-max_y,max_y), _pos.z + ofRandom(max_x,-max_x)) );
    //		addParticle( Vec3f( _pos.x , _pos.y, _pos.z ) ); // + Rand::randVec3f() * 300 );
};

void MSAParticleSystem3D_Abstract::addParticle( Vec3f _pos )
{
    TT_Custom_MSAParticle3D * p = createParticle(_pos);
    defaultgroup->addParticle( p );
    p->release();
}

// ----------------------------------------------------- 
TT_Custom_MSAParticle3D * MSAParticleSystem3D_Abstract::createParticle( Vec3f _pos )
{
    TT_Custom_MSAParticle3D *p = new TT_Custom_MSAParticle3D( _pos );
    physics.addParticle(p);
    return p;
}
// ----------------------------------------------------- MOUSE PARTICLE
void MSAParticleSystem3D_Abstract::addMouseParticle()
{
    physics.addParticle( &mouse_node );
	mouse_node.makeFixed();
	mouse_node.setMass(1);
	mouse_node.moveTo( Vec3f(0, 0, 0) );
	mouse_node.setRadius( 1 );
    mouse_node.enableCollision();
}

void MSAParticleSystem3D_Abstract::moveMouseParticle( int x, int y, int z )
{
    //  static int oldMouseX = -10000;
    //	static int oldMouseY = -10000;
    //	int velX = x - oldMouseX;
    //	int velY = y - oldMouseY;
	mouse_node.moveTo(Vec3f(x, y, z));
    //	mouseNode.moveBy(Vec3f(velX, 0, velY));
    //	oldMouseX = x;
    //	oldMouseY = y;
}

//------------------------------------------------------ SETTINGS
void MSAParticleSystem3D_Abstract::addSettings( ofxSimpleGuiToo & _gui )
{
    gui_particle_page = &_gui.addPage("Particle System");
    _gui.addTitle( "Particle Settings"); //.setNewColumn(true);
	_gui.addSlider( "gravity", gravity, -5, 5);
    _gui.addSlider( "numberOfParticles", numberOfParticles, 0, 100000 );
    
    for (int i=0; i<groups.size(); i++) {
        groups[i]->addSettings( _gui );
    }
    
}

// ----------------------------------------------------- 
void MSAParticleSystem3D_Abstract::setXMLFilename( string _xml_filename )
{
    xml_filename = _xml_filename;
    gui_particle_page->setXMLName(xml_filename);
    
}
