

#include "MSAParticleGroup3D.h"

#define MAX_GROUP_PARTICLES 29000

void MSAParticleGroup3D::setup()
{
    max_particles = MAX_GROUP_PARTICLES;
    
    mass_min = .9;
    mass_max = .99;
    
    bounce_min = 0.1;
    bounce_max = 0.1;
    
    node_min = 1;
    node_max = 20;
    
    drag_min = .90;
    drag_max = .99;
    
    particle_default_color = 0xFFFFFF;
    
    enable_collision = false;
    enable_wrapping = true;
    
    alpha_min = 0.99;
    alpha_max = 2;
    
    cout << "MSAParticleGroup3D setup called" << endl;
}

void MSAParticleGroup3D::update()
{
    if ( group.size() > max_particles ) {
        resizeParticleGroup();
    }
}

void MSAParticleGroup3D::draw()
{ 
    vector<TT_Custom_MSAParticle3D*>::iterator it = group.begin();
    
    while( it != group.end() ) {
        TT_Custom_MSAParticle3D * p = *it;
        if( p->isDead() ) {
            it = group.erase(it);
        } else {
            ofPushStyle();
            ofFill();
            ofSetHexColor( particle_default_color );
            ofCircle( p->getPosition().x, p->getPosition().y, p->getPosition().z, p->getRadius() );
            ofPopStyle();
            it++;
        }
    }
}

void MSAParticleGroup3D::addParticle( TT_Custom_MSAParticle3D * _p )
{
    setParticleProperties(_p);
    group.push_back(_p);
}

void MSAParticleGroup3D::setParticleProperties( TT_Custom_MSAParticle3D * _p )
{
	float mass		= ofRandom( mass_min, mass_max );
	float bounce	= ofRandom( bounce_min, bounce_max );
    float drag      = ofRandom(drag_min, drag_max);
    float alpha     = ofRandom( alpha_min, alpha_max );
    
    if (enable_collision) {
        _p->enableCollision();
    } else {
        _p->disableCollision();
    }
    
    if (enable_wrapping) {
        _p->setWrap(true, true);
    }
    
    if ( enable_fadeout )
        _p->enableFadeOut();
    
    _p->setBounce(bounce);
	_p->setMass(mass)->setDrag(drag)->makeFree();
    _p->setAlpha(alpha);
    
    // give them a push
    _p->setVelocity( Vec3f(ofRandom(-100,100),ofRandom(-10,10),0 ) );
}

void MSAParticleGroup3D::resizeParticleGroup()
{
    int i = group.size()-1;
    while ( group.size() > max_particles ) {
        TT_Custom_MSAParticle3D * p = group[ i ];
        if ( !p->isDead() ) {
            p->kill();
        }
        group.erase( group.begin() + i );
        i--;
    }
    
}

void MSAParticleGroup3D::killParticles()
{
    int save_max_particles = max_particles;
    max_particles = 0;
    resizeParticleGroup();
    max_particles = save_max_particles;
}

//------------------------------------------------- SETTINGS
void MSAParticleGroup3D::addSettings( ofxSimpleGuiToo & _gui )
{
    _gui.addTitle( instance_name + " Settings").setNewColumn(true);
    
	_gui.addSlider( instance_name + " mass min", mass_min, 0.1, 1);
	_gui.addSlider( instance_name + " mass max", mass_max, 0.1, 1);
    
	_gui.addSlider( instance_name + " drag min", drag_min, 0.1, 1);
	_gui.addSlider( instance_name + " drag max", drag_max, 0.1, 1);
    
//    _gui.addSlider( "bounce min", bounce_min, 0, 1);
//	_gui.addSlider( "bounce max", bounce_max, 0, 1);
    
    _gui.addToggle( instance_name + " collision", enable_collision );
    _gui.addToggle( instance_name + " wrapping", enable_wrapping );
    
    
//	_gui.addSlider( instance_name + " drag min", drag_min, 0.1, 1);
//	_gui.addSlider( instance_name + " drag max", drag_max, 0.1, 1);
    
    _gui.addToggle( instance_name + " enableFadeOut", enable_fadeout );

}