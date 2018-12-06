#include "ParticleManager.h"

ParticleManager::ParticleManager()
	: Rad(1800)
	, Vel(0.1)
{
}

ParticleManager::~ParticleManager()
= default;



void ParticleManager::setup_particles()
{
	for (int i = 0; i < countCircles; i++) {
		Particle particle;
		particles[i] = particle;
	}
}

void ParticleManager::set_time()
{
	currentTime = ofGetElapsedTimef();
	deltaTime = currentTime - timeZero;
	deltaTime = ofClamp(deltaTime, 0.0, 0.1);
	timeZero = currentTime;
	
}
float ParticleManager::get_deltaTime()
{
	return 0.0f;

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

void ParticleManager::set_colors(int j)
{
		float color = 0.0;
		colors.push_back(color);
		colors[j] = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	
}

void ParticleManager::draw_circle(float bass)
{
	for (int i = 0; i < countCircles; i++) {

		ofCircle(particles[i].circleXY, bass);

	}
}

float ParticleManager::set_distance(int j, int k)
{
	return ofDist(particles[j].circleXY.x, particles[j].circleXY.y, particles[k].circleXY.x, particles[k].circleXY.y);
}

void ParticleManager::set_color_line(int j)
{
	return ofSetColor(colors[j]);
}

void ParticleManager::draw_line(int j, int k)
{
	ofLine(particles[j].circleXY, particles[k].circleXY);
}
void ParticleManager::change_positions(int j, float Vel, int Rad)
{
		particles[j].circlePosition += Vel * deltaTime;
		particles[j].circleXY.x = ofSignedNoise(particles[j].circlePosition.x) *Rad;
		particles[j].circleXY.y = ofSignedNoise(particles[j].circlePosition.y) *Rad;

}
