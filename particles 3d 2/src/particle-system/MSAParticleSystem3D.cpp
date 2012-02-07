
#include "MSAParticleSystem3D.h"

#define GRAVITY         -0.1
#define SECTOR_COUNT    1

void MSAParticleSystem3D::setup()
{
	width = ofGetWidth();
	height = ofGetHeight();
    
    physics.verbose = false;			// dump activity to log
    gravity = GRAVITY;
    physics.setGravity(Vec3f(0, gravity, 0) );
    // set world dimensions, not essential, but speeds up collision
	physics.setWorldSize(Vec3f(-width, -height, -width), Vec3f(width, height, width));
	physics.setSectorCount(SECTOR_COUNT);
    
    physics.setDrag(0.97f);
    physics.setDrag(1);		// FIXTHIS
    physics.enableCollision();
    
    initScene();
}

void MSAParticleSystem3D::initScene()   
{
    physics.clear();
    addMouseParticle();
    createParticleGroups();
    physics.setGravity(Vec3f(0, gravity, 0) );
}

void MSAParticleSystem3D::createParticleGroups()
{
    maingroup = new MSAParticleGroup3D();
    maingroup->setup();
}

// ----------------------------------------------------- LOOPS 
void MSAParticleSystem3D::update()
{
	physics.update();    
    
    maingroup->update();
    
    // we show this number in the UI //
    numberOfParticles = physics.numberOfParticles();
}

// ----------------------------------------------------- DRAW
void MSAParticleSystem3D::draw()
{
    maingroup->draw();
    
    // draw mouse //
    ofPushStyle();
    ofFill();
    ofSetColor( 255,0,255 );
    ofCircle( mouse_node.getPosition().x, mouse_node.getPosition().y, mouse_node.getPosition().z, mouse_node.getRadius() );
    ofPopStyle();
}

// ----------------------------------------------------- PARTICLE MANAGMENT
void MSAParticleSystem3D::addParticles( Vec3f _pos, int _count)
{
    for(int i=0; i<_count; i++)
		addParticle( Vec3f( _pos.x + ofRandom(-width,width), _pos.y + ofRandom(-height,height), _pos.z + ofRandom(-width,width)) ); // + Rand::randVec3f() * 300 );
}

void MSAParticleSystem3D::addParticle( Vec3f _pos  )
{
    MSAParticleGroup3D * current_group =  0;
    TT_Custom_MSAParticle3D * p = createParticle(_pos);
    
    current_group = maingroup;
    current_group->addParticle( p );
    current_group->setParticleProperties(p);
    
    p->release();
}

TT_Custom_MSAParticle3D * MSAParticleSystem3D::createParticle( Vec3f _pos )
{
//    MSA::Physics::Particle2D *p = new MSA::Physics::Particle2D( _pos );
    
    TT_Custom_MSAParticle3D *p = new TT_Custom_MSAParticle3D( _pos );
    physics.addParticle(p);
    return p;
}

// ----------------------------------------------------- MOUSE PARTICLE
void MSAParticleSystem3D::addMouseParticle()
{
    physics.addParticle(&mouse_node);
	mouse_node.makeFixed();
	mouse_node.setMass(1);
	mouse_node.moveTo( Vec3f(0, 0, 0) );
	mouse_node.setRadius( 1 );
    mouse_node.enableCollision();
}

void MSAParticleSystem3D::moveMouseParticle( int x, int y, int z )
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

// ----------------------------------------------------- UTILITY
void MSAParticleSystem3D::killAll()
{
    maingroup->killParticles();
}

//------------------------------------------------------ SETTINGS
void MSAParticleSystem3D::addSettings( ofxSimpleGuiToo & _gui )
{
    gui_particle_page = &_gui.addPage("Particle System");
    _gui.addTitle( "Particle Settings"); //.setNewColumn(true);
	_gui.addSlider( "gravity", gravity, -1, 1);
    maingroup->addSettings( "Main Group", _gui );
}

void MSAParticleSystem3D::setXMLFilename( string _xml_filename )
{
    xml_filename = _xml_filename;
    gui_particle_page->setXMLName(xml_filename);
}



