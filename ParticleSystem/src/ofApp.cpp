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
	
	if (mouseHasPressed) {
		if (currentTime2 >= lastColorTime + newCircles.data()->lifeTime)
		{
			delete_Circle();
			lastColorTime = currentTime2;
		}

		for (int i = 0; i < newCircles.size(); i++) {
			sound_manager.set_smooth_sound();
			const float smoothVelocity = sound_manager.return_smooth(100);
			Vel = ofMap(smoothVelocity, 0, 0.12, 0.7, 1.5);
			RepulsionForce(i);
			newCircles[i].update(Vel);
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(World.color);
	ofDrawCircle(World.position, World.radius);
	if (mouseHasPressed) {
		float dist = 250;
		float circleRadius = sound_manager.get_bassValueToCircle(1);
		float lineRadius = sound_manager.get_bassValueToLine(1);
		for (int i = 0; i < newCircles.size(); i++) {
			if (i > 0) {
				for (int k = i + 1; k < newCircles.size(); k++) {
					float distance = ofDist(newCircles[i].position.x, newCircles[i].position.y, newCircles[k].position.x, newCircles[k].position.y);
					
					if (distance < dist) {
						ofSetLineWidth(lineRadius);
						ofLine(newCircles[i].position, newCircles[k].position);
					}
				}
			}
			
			newCircles[i].draw(circleRadius);
		}
	}


	
}
void ofApp::RepulsionForce(int i) {
	ofVec2f mWorld;
	ofVec2f Object;
	Object.set(newCircles[i].position.x, newCircles[i].position.y);
	mWorld.set(World.position.x, World.position.y);
	ofVec2f diff = mWorld - Object;
	diff.normalize();
	float length = diff.length();
	ofPoint gravityForce;
	gravityForce = 0.7 * (1 / (length*length)) * diff;

	newCircles[i].force = gravityForce - newCircles[i].acceleration;
}
//--------------------------------------------------------------
void ofApp::delete_Circle()
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
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

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
void ofApp::mouseEntered(int x, int y)
{
	
}
void ofApp::mouseExited(int x, int y)
{
	
}
