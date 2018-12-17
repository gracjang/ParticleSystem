#pragma once
#include "ofMain.h"
class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void setup_sound(string pathSong);
	void set_smooth_sound();
	float get_bassValueToCircle(int elementOfArray);
	float get_bassValueToLine(int elementOfArray);
	float get_bassValue(int elementOfArray);
	float set_radius_line(int elementOfArray);
	float return_smooth(int elementOfArray);
	ofSoundPlayer _sound;
	float * _smooth;
	int _bands;
};

