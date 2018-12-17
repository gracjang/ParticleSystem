#include "SoundManager.h"



SoundManager::SoundManager()
	: _bands(256)
	, _smooth(new float[8192])
		
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::setup_sound(string pathSong)
{
	_sound.loadSound(pathSong);

	for (int x = 0; x < 8192; x++) {
		_smooth[x] = 0;
	}
	_sound.setLoop(true);
	_sound.play();
}

void SoundManager::set_smooth_sound()
{
	float * value = ofSoundGetSpectrum(_bands);

	for (int k = 0; k < _bands; k++) {
		_smooth[k] *= 0.8f;
		_smooth[k] = max(_smooth[k], value[k]);
	}
	
}

float SoundManager::get_bassValueToCircle(int elementOfArray )
{	

	float bass = (_smooth[elementOfArray] * 7 > 5) ? _smooth[elementOfArray] * 8 : 3;
	return bass;
}

float SoundManager::get_bassValueToLine(int elementOfArray)
{
	float bass2 = (_smooth[elementOfArray] * 7 > 5) ? _smooth[elementOfArray] * 1.2 : 0.5;
	return bass2;
}

float SoundManager::return_smooth(int elementOfArray)
{
	return _smooth[elementOfArray];
}
