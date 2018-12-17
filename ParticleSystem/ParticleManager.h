#pragma once
#include "ofMain.h"


class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();
	void set_time();

	int set_radius(const float smooth_radius);
	float set_velocity(const float smooth_velocity);
	float deltaTime;
	
private:
	
	float currentTime;
	float timeZero = 0;
	int Rad;
	float Vel;
	
};
