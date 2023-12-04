#include "Timer.h"

Timer::Timer()
{

};

float Timer::globalTimeInSeconds()
{
	float globalTime = SDL_GetTicks(); //this is the amounts of ms that have passed since the game started
	globalTime = globalTime * 0.001f; // we turn the MS into seconds

	return globalTime;
};