#pragma once

#include "ofMain.h"
class Particle
{
public:
	void setRandomValue();
	Particle();
	~Particle();
	int radius;
	float height = ofGetHeight() / 2;
	ofVec2f circlePosition;
	ofPoint circleXY;
	vector<ofColor> colors;
};

