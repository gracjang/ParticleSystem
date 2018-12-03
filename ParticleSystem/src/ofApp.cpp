#include "ofApp.h"
int Rad = 1800; // radius
int radius = 3;
const int countCircles = 200; // number of circles
float circlePositionX[countCircles], circlePositionY[countCircles];
ofPoint circleXY[countCircles];
float timeZero = 0;
float Vel = 0.1;

struct Circle {
	ofColor color;
	int radius;
	float height= ofGetHeight()/2;
	float width = ofGetWidth()/2;
};
	

//--------------------------------------------------------------
void ofApp::setup() {
	sound.loadSound("surface.mp3");
	smooth = new float[8192];
	
	for (int x = 0; x < 8192; x++) {
		smooth[x] = 0;
	}
	bands = 256;
	sound.setLoop(true);
	sound.play();
	for (int i = 0; i < countCircles; i++) {
		circlePositionX[i] = ofRandom(0, 1000);
		circlePositionY[i] = ofRandom(0, 1000);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	float * value = ofSoundGetSpectrum(bands);
	
	float time = ofGetElapsedTimef();
	float deltaTime = time - timeZero;
	deltaTime = ofClamp(deltaTime, 0.0, 0.1);
	timeZero = time;
	for (int k = 0; k < bands; k++) {
		smooth[k] *= 0.8f;
		smooth[k] = max(smooth[k], value[k]);

		//Vel += smooth[k] * deltaTime;
		//radius = smooth[k] * 10;


	}
	Rad = ofMap(smooth[2], 1, 2, 500, 700, true);
	Vel = ofMap(smooth[100], 0, 0.1, 0.5, 1.2);

	for (int j = 0; j < countCircles; j++) {
		circlePositionX[j] += Vel * deltaTime;
		circlePositionY[j] += Vel * deltaTime;
		circleXY[j].x = ofSignedNoise(circlePositionX[j]) * Rad;
		circleXY[j].y = ofSignedNoise(circlePositionY[j]) * Rad;

		float color;
		colors.push_back(color);
		colors[j] = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	}
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0, 0, 0);	//Set up the background
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofFill();


	float bass = (smooth[1] * 7 > 5) ? smooth[1] * 6 : 1;
	float bass2 = (smooth[1] * 7 > 5) ? smooth[1] * 1.8 : 1;
	for (int i = 0; i < countCircles; i++) {
			ofCircle(circleXY[i], bass);
			
		}
	
	float dist = 140;	
	
	for (int j = 0; j < countCircles; j++) {
		for (int k = j + 1; k < countCircles; k++) {
			float distance = ofDist(circleXY[j].x, circleXY[j].y, circleXY[k].x, circleXY[k].y);
			if (distance < dist) {
				float alpha = ofMap(distance, 0, 180, 150, 0);
				ofSetColor(colors[j]);
				ofSetLineWidth(bass2);
				ofLine(circleXY[j], circleXY[k]);
			}
		}
	}
	
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
void ofApp::mouseEntered(int x, int y) {}
void ofApp::mouseExited(int x, int y) {}