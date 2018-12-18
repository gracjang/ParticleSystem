#pragma once

#include "ofMain.h"
#include "../SoundManager.h"
#include "../ParticleManager.h"
#include "../MyCircle.h"
#include "../CenterBall.h"


class ofApp : public ofBaseApp{

	public:
		ofApp();
		void setup();
		void update();
		void draw();
		void RepulsionForce(int i);
	
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void delete_Circle();
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		SoundManager sound_manager;
		ParticleManager particle_manager;
		CenterBall World;
private:
		float lastColorTime;
		float Vel = 0.1;
		vector <MyCircle> newCircles;
		bool mouseHasPressed;
		
};
