#pragma once

#include "ofMain.h"
#include "../Particle.h"


#define countCircles 150
class ofApp : public ofBaseApp{

	public:
		ofApp();
		void setup();
		void update();
		void draw();
		Particle particles[countCircles];
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		float currentTime;
		float lastColorTime;
		ofSoundPlayer sound;
		int bands;
		float * smooth;
		vector<ofColor> colors;
		ofPolyline line;
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		int Rad = 1800; // radius
		int radius = 3;
		
		float timeZero = 0;
		float Vel = 0.1;
		
};
