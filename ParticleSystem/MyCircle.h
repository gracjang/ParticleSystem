#pragma once
#include "ofMain.h"
class MyCircle {
public:
	void setup(float initialX, float initialY);
	void update(float Vel);
	void draw(float Radius);
	ofPoint position;
	float counter;
	float minRadius, maxRadius;
	ofColor color;
	ofPoint force;
	ofPoint velocity;
	ofPoint acceleration;
	float lifeTime;
	int mass;
	

};
