#include "ofApp.h"



ofApp::ofApp()
{
}

//--------------------------------------------------------------
void ofApp::setup() {
	sound_manager.setup_sound("song.mp3");
	particle_manager.setup_particles();


}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	
	
	particle_manager.set_time();
	sound_manager.set_smooth_sound();
	const float smoothRadius = sound_manager.return_smooth(2);
	const float smoothVelocity = sound_manager.return_smooth(100);

	Rad = ofMap(smoothRadius, 1, 2, 500, 700, true);
	Vel = ofMap(smoothVelocity, 0, 0.1, 0.5, 1.2);
	for (int j = 0; j < countCircles; j++) {
		particle_manager.change_positions(j, Vel, Rad);
		particle_manager.set_colors(j);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0, 0, 0);	//Set up the background
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	


	float bass = sound_manager.set_radius_circle(1);

	for (int i = 0; i < countCircles; i++) {
		
		particle_manager.draw_circle(bass);
			
		}
	
	float dist = 90;	
	float delay = 0.5;
	for (int j = 0; j < countCircles; j++) {
		for (int k = j + 1; k < countCircles; k++) {
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