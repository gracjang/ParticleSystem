#include "ofApp.h"



ofApp::ofApp()
{
}

//--------------------------------------------------------------
void ofApp::setup() {
	sound_manager.setup_sound("song.mp3");
	ofBackground(0);
	ofEnableSmoothing();
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	ofEnableAlphaBlending();
	mouseHasPressed = false;
	
	

}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	float currentTime2 = ofGetElapsedTimef();
	float delay = 1.0;
	if (mouseHasPressed) {
		if (currentTime2 >= lastColorTime + delay)
		{
			delete_Circle();
			lastColorTime = currentTime2;
		}

		for (int i = 0; i < newCircles.size(); i++) {
			sound_manager.set_smooth_sound();
			const float smoothVelocity = sound_manager.return_smooth(100);
			Vel = ofMap(smoothVelocity, 0, 0.15, 0.7, 1.5);
			newCircles[i].update(Vel);
		}

	

	}

	/*
	 *particle_manager.set_time();
	sound_manager.set_smooth_sound();
	const float smoothRadius = sound_manager.return_smooth(2);
	const float smoothVelocity = sound_manager.return_smooth(100);

	Rad = ofMap(smoothRadius, 1, 2, 500, 700, true);
	Vel = ofMap(smoothVelocity, 0, 0.1, 0.2, 1.2);
	for (int j = 0; j < particles.size(); j++) {
		particle_manager.change_positions(j, Vel, Rad);
		particle_manager.set_colors(j);
	}
	*/
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofDrawBitmapString("click to add circles, press <backspace> to delete", 10, 20);
	if (mouseHasPressed) {
		float circleRadius = sound_manager.get_bassValueToCircle(1);
		float lineRadius = sound_manager.get_bassValueToLine(1);
		for (int i = 0; i < newCircles.size(); i++) {
			if (i > 0) {
				ofLine(newCircles[i - 1].x, newCircles[i - 1].y, newCircles[i].x, newCircles[i].y);
				ofSetLineWidth(lineRadius);
			}
			
			newCircles[i].draw(circleRadius);
		}
	}


	
	/*
	 ofBackground(0, 0, 0);	//Set up the background
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	


	float bass = sound_manager.set_radius_circle(1);
	for (int i = 0; i < particles.size(); i++) {

		particle_manager.draw_circle(bass);
		
			
		}
	
	float dist = 90;	
	float delay = 0.8;
	for (int j = 0; j < particles.size(); j++) {
		for (int k = j + 1; k < particles.size(); k++) {
			float distance = particle_manager.set_distance(j,k);
			if (distance < dist) {
				float currentTime2 = ofGetElapsedTimef();
				ofSetLineWidth(0.8);
				if (currentTime2 >= lastColorTime + delay)
				{
					particle_manager.set_color_line(j);
					lastColorTime = currentTime2;
					

				}

				particle_manager.draw_line(j, k);
			}
		}
	}
	
	ofPopMatrix();*/
	
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

void ofApp::delete_Circle( )
{
	if (newCircles.size() > 1) {
		newCircles.erase(newCircles.end() - 1);
	}

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	float currentTime2 = ofGetElapsedTimef();
	float delay = 0.1;
	if (currentTime2 >= lastColorTime + delay)
	{

		if (x != 0 && y != 0) {
			
			mouseHasPressed = true;
			MyCircle newCircle;
			newCircle.setup(x, y);
			newCircles.push_back(newCircle);
			lastColorTime = currentTime2;
		}
	}

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