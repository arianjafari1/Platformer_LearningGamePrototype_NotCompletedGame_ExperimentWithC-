#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <iostream>


class FontRenderer
{
public:
	FontRenderer(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y);

	void init();

	void render(std::string text);
	void clean();

private:
	float x;
	float y;

	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Rect textRec = SDL_Rect();
	float textWidth;

	int windowWidth;
	int windowHeight;

};

