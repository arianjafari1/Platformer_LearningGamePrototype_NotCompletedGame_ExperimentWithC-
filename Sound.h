#pragma once

#include <SDL_mixer.h>
#include <sstream>
#include <vector>

enum Sounds
{
	BLASTERSHOT=0,
	WALKING=1,
	THEMESONG=2,
	JUMPING=3,
	TOTAL_SOUNDS
};


class Sound
{
public:
	Sound();
	virtual ~Sound();

	void PlaySound(int sound);

private:
	Mix_Music* musicPlayer = nullptr;
	std::vector<Mix_Chunk*> soundFiles;

};

