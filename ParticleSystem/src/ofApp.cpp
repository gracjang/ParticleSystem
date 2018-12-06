#include "ofApp.h"



ofApp::ofApp()
	
{
}

//--------------------------------------------------------------
void ofApp::setup() {

	sound.loadSound("song.mp3");
	smooth = new float[8192];
	
	for (int x = 0; x < 8192; x++) {
		smooth[x] = 0;
	}
	bands = 256;
	sound.setLoop(true);
	sound.play();
	for (int i = 0; i < countCircles; i++) {
		Particle particle;
		particles[i] = particle;
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	float * value = ofSoundGetSpectrum(bands);
	currentTime = ofGetElapsedTimef();
	float deltaTime = currentTime - timeZero;
	deltaTime = ofClamp(deltaTime, 0.0, 0.1);
	timeZero = currentTime;
	for (int k = 0; k < bands; k++) {
		smooth[k] *= 0.8f;
		smooth[k] = max(smooth[k], value[k]);

		//Vel += smooth[k] * deltaTime;
		//radius = smooth[k] * 10;


	}
	Rad = ofMap(smooth[2], 1, 2, 500, 700, true);
	Vel = ofMap(smooth[100], 0, 0.1, 0.5, 1.2);

	for (int j = 0; j < countCircles; j++) {
		particles[j].circlePosition += Vel * deltaTime;
		particles[j].circleXY.x = ofSignedNoise(particles[j].circlePosition.x) *Rad;
		particles[j].circleXY.y = ofSignedNoise(particles[j].circlePosition.y) *Rad;
		float color=0.0;
		colors.push_back(color);
		colors[j] = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	}
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0, 0, 0);	//Set up the background
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	


	float bass = (smooth[1] * 7 > 5) ? smooth[1] * 1.5: 1;
	float bass2 = (smooth[1] * 7 > 5) ? smooth[1] * 0.5 : 0.2;
	for (int i = 0; i < countCircles; i++) {
		
		ofCircle(particles[i].circleXY, bass);
			
		}
	
	float dist = 75;	
	float delay = 0.5;
	for (int j = 0; j < countCircles; j++) {
		for (int k = j + 1; k < countCircles; k++) {
			float distance = ofDist(particles[j].circleXY.x, particles[j].circleXY.y, particles[k].circleXY.x, particles[k].circleXY.y);
			if (distance < dist) {
				float currentTime2 = ofGetElapsedTimef();
				ofSetLineWidth(0.8);
				if (currentTime2 >= lastColorTime + delay)
				{
					ofSetColor(colors[j]);
					lastColorTime = currentTime2;
					

				}

				ofLine(particles[j].circleXY, particles[k].circleXY);
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