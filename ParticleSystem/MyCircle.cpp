#include "MyCircle.h"

void MyCircle::setup(float initialX, float initialY) {
	position.x = initialX;
	position.y = initialY;
	velocity.x = ofRandom(-10, 10);
	velocity.y = ofRandom(-10, 10);
	mass = ofRandom(1, 5);
	counter = 0;
	minRadius = 10;
	maxRadius = 20;
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}


//--------------------------------------------------------------
void MyCircle::update(float Vel) {
	acceleration = force / mass;
	velocity = velocity + acceleration;
	position = position + velocity * Vel;

	if (position.x <45|| position.x+45>ofGetWidth()) {
		velocity.x *= -1;
		
	}
	if (position.y<45|| position.y+45>ofGetHeight()) {
		velocity.y*= -1;
		
	}
	counter += 0.1;
}



//--------------------------------------------------------------
void MyCircle::draw(float radius) {
	ofSetColor(127, 100);
	ofCircle(position,maxRadius + sin(counter)*(maxRadius - minRadius));
	ofSetColor(color);
	ofCircle(position, radius);
}
