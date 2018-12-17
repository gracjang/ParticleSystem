#include "ParticleManager.h"

ParticleManager::ParticleManager()
	: Rad(1800)
	, Vel(0.1)
{
}

ParticleManager::~ParticleManager()
= default;




void ParticleManager::set_time()
{
	currentTime = ofGetElapsedTimef();
	deltaTime = currentTime - timeZero;
	deltaTime = ofClamp(deltaTime, 0.0, 0.1);
	timeZero = currentTime;
	
}


int ParticleManager::set_radius(const float smooth_radius)
{
	Rad = ofMap(smooth_radius, 1, 2, 500, 700, true);
	return Rad;
}

float ParticleManager::set_velocity(const float smooth_velocity)
{
	int Vel = ofMap(smooth_velocity, 0, 0.1, 0.5, 1.2);
	return Vel;
}

