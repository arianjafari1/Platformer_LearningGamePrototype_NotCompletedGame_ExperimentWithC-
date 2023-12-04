#pragma once
#include <SDL.h>
#include <SDL_IMAGE.h>
#include <iostream>


class TileMap
{
public:
	TileMap(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y);

	void init();
	void render();
	void update();
	void clean();
	float getX()
	{
		return x;
	}
	void setX(float newX)
	{
		x += newX;
	}

	float getY()
	{
		return y;
	}
	void setY(float newY)
	{
		y += newY;
	}

	float getTileWidth()
	{
		return tileWidth;
	};

	SDL_Rect getPortion()
	{
		return portion;
	};

private:
	float x = 0.0f;
	float y = 0.0f;
	float tileWidth;

	/*float multiplier;*/

	float percentageTileWidthComparedToScreen = 3.0f / 100.0f; //20%

	SDL_Surface* imageTile = nullptr;

	int windowWidth = 0;
	int windowHeight = 0;

	SDL_Rect portion = SDL_Rect(); //created a rectangle object to copy the entire texture to just a portion of the renderer
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;


};

