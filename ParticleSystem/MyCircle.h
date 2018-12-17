#pragma once
#include "ofMain.h"
class MyCircle {
public:
	void setup(float initialX, float initialY);
	void update(float Vel);
	void draw(float Radius);
	float x, y;
	ofPoint position;
	float speedX, speedY;
	float counter;
	float minRadius, maxRadius;
	ofColor color;

};
