#include "MyCircle.h"

void MyCircle::setup(float initialX, float initialY) {
	x = initialX;
	y = initialY;
	speedX = ofRandom(-10, 10);
	speedY = ofRandom(-10, 10);
	counter = 0;
	minRadius = 10;
	maxRadius = 20;
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}


//--------------------------------------------------------------
void MyCircle::update(float Vel) {
	x += speedX * Vel;
	y += speedY * Vel;

	if (x <45|| x+45>ofGetWidth()) {
		speedX *= -1;
		
	}
	if (y<45|| y+45>ofGetHeight()) {
		speedY *= -1;
		
	}
	counter += 0.1;
}



//--------------------------------------------------------------
void MyCircle::draw(float radius) {
	ofSetColor(127, 100);
	ofCircle(x, y, maxRadius + sin(counter)*(maxRadius - minRadius));
	ofSetColor(color);
	ofCircle(x, y, radius);
}
