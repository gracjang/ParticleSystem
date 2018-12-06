#pragma once

#include "ofMain.h"
#include "../Particle.h"
#include "../SoundManager.h"
#include "../ParticleManager.h"


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
		
		
		vector<ofColor> colors;
		ofPolyline line;
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		SoundManager sound_manager;
		ParticleManager particle_manager;
		int Rad = 1800; // radius
		int radius = 3;
		float lastColorTime;
		float Vel = 0.1;
		
};
