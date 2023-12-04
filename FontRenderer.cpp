#include "FontRenderer.h"

FontRenderer::FontRenderer(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y)
{
	renderer = sdlRenderer;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	x = _x;
	y = _y;
};

void FontRenderer::init()
{
	int init = TTF_Init();
	if (init != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	font = TTF_OpenFont("assets/fonts/OpenSans-Regular.ttf", 40);
	if (font == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
	}
};

void FontRenderer::render(std::string text)
{
	SDL_Color color = SDL_Color();
	color.r = 120; //red
	color.g = 0; //green
	color.b = 60; //blue
	color.a = 255; //transparecy

	SDL_Surface* textImage = TTF_RenderText_Solid(font, text.c_str(), color);  //This will create an image of the text that we will input

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textImage); //with the textImage we render it the same way we would do a Sprite image, as a texture
	
	textRec = {(int)x, (int)y, textImage->w, textImage->h};


	SDL_RenderCopy(renderer, texture, NULL, &textRec); /*first parameters are targer renderer and source texture, third one is the portion of texture that we want to copy,
	 and the fourth one is the portion of the screen to target (if we apply NULL to the last to it targets the whole render)  */


	//since this is a static text that we already renderer, we not longer need the image or the the texture
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textImage);
};


void FontRenderer::clean()
{
	TTF_CloseFont(font);

};