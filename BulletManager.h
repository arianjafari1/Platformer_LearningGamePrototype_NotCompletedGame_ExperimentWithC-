#pragma once
#include <SDL.h>
#include <SDL_IMAGE.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"


struct Bullet
{
	float x, y, distance;
};

class BulletManager
{
public:
	BulletManager(SDL_Renderer* sdlRenderer, Player* _player, int _windowWidth);

	void init();
	void processInput(bool keyDown);
	void render();
	void update();
	void clean();


private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* bulletTexture= nullptr;
	std::vector<Bullet> bullets;

	Player* player = nullptr; // need a reference to the player for the pos to shoot from

	const int shootTimerMS = 500; // timer in between shots
	
	const int bulletVelocity = 5;

	unsigned int lastShot = 0; // int that can only hold non-negative whole number values


	//float percentageBulletWidthComparedToScreen = 0.000001f; //20%
	int windowWidth = 0;
};

