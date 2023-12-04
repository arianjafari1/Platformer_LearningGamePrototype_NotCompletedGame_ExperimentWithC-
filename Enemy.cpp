#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y)
{
	renderer = sdlRenderer;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	x = _x;
	y = _y;
};

void Enemy::init()
{
	imageEnemy = IMG_Load("assets/sprites/enemy.png");
	if (imageEnemy == nullptr)
	{
		std::cout << "Could not load image!" << std::endl;
		return;
	};
	texture = SDL_CreateTextureFromSurface(renderer, imageEnemy);
}

void Enemy::render()
{
	portion.x = (int)x; //set pos on axis X to the x from the header file
	portion.y = (int)y; //set pos on axis Y to the y from the header file

	enemyWidth = percentagePlayerWidthComparedToScreen * (float)windowWidth; // making playerWidth always be equal to 20% of the width of the screen
	portion.w = portion.h = (int)enemyWidth; //assigning width and the height of the player to player width
	 //= (int)playerWidth; // the reason why playerHeight is also assigned playerWidth is so we don't have a stretched enemy

// function to copy texture to our current renderer
	SDL_RenderCopy(renderer, texture, NULL, &portion); /*first parameters are targer renderer and source texture, third one is the portion of texture that we want to copy,
	 and the fourth one is the portion of the screen to target (if we apply NULL to the last to it targets the whole render)  */

};

void Enemy::update()
{


};



void Enemy::clean()
{

};
