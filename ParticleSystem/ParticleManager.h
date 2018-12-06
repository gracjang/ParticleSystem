#pragma once
#include "ofMain.h"
#include "Particle.h"


#define countCircles 100
class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();
	void setup_particles();
	void set_time();
	float get_deltaTime();

	int set_radius(const float smooth_radius);
	float set_velocity(const float smooth_velocity);
	void set_colors(int j );
	void draw_circle(float bass);
	float set_distance(int j, int k);
	void set_color_line(int j);
	void draw_line(int j, int k);
	void change_positions(int j,float Vel, int Rad);
	
private:
	
	vector<ofColor> colors;
	float deltaTime;
	Particle particles[countCircles];
	float currentTime;
	float timeZero = 0;
	int Rad;
	float Vel;
	
};
