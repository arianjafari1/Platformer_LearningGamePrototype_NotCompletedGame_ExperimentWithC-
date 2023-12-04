#pragma once

#include <SDL.h>
#include <SDL_IMAGE.h>
#include <iostream>

class Enemy
{
public:
	Enemy(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y);
	
	void init();
	void render();
	void update();
	void clean();
	
	const int defaultScreenWidth = 1280; // these are the height and width of the screen at which assets are being positioned
	const int defaultScreenHeight = 720;
	
	const float newWidthDividedByDefaultX = (float)windowWidth / (float)defaultScreenWidth; /* how many times do we need to multiply the pos of */
	const float newHeightDividedByDefaultY = (float)windowHeight / (float)defaultScreenHeight; 	/*an asset to get it back to its place after changing the resolution */


private:
	float x = 0.0f;
	float y = 0.0f;
	float enemyWidth;
	const float percentageNumber = 10.0f;
	float percentagePlayerWidthComparedToScreen = percentageNumber / 100.0f;; //20%
	
	SDL_Surface* imageEnemy = nullptr;
	
	int windowWidth = 0;
	int windowHeight = 0;
	
	SDL_Rect portion = SDL_Rect(); //created a rectangle object to copy the entire texture to just a portion of the renderer
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;

};

