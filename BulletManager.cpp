#include "BulletManager.h"

BulletManager::BulletManager(SDL_Renderer* sdlRenderer, Player* _player, int _windowWidth)
{
	renderer = sdlRenderer;
	player = _player;
	windowWidth = _windowWidth;
};
void BulletManager::init()
{
	SDL_Surface* surface = IMG_Load("assets/sprites/blasterBullet.png");
	this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
};

void BulletManager::processInput(bool keyDown)
{
	if (keyDown) //checks for keypress
	{
		if (SDL_GetTicks() - lastShot > shootTimerMS) // checks to make sure that user than hold the f key down to spawn bullets
		{
			// this adds the Bullet element at the end of the dynamic vector array
			bullets.push_back(Bullet{ player->getX() + player->getPlayerWidth(), player->getY() + player->getPlayerWidth() / 4, 0.0f });
			lastShot = SDL_GetTicks();
		};
	};
};

void BulletManager::render()
{
	for (auto &b : bullets)
	{
		b.x += bulletVelocity;
		b.distance = b.x;
	};

	//remove bullet after reaching a certain distance
	auto remove = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) {return b.distance > 1500; });
	bullets.erase(remove, bullets.end());

	for (auto &b : bullets)
	{
		SDL_Rect dest = { b.x, b.y, 32, 32 };
		//float bulletWidth = percentageBulletWidthComparedToScreen * (float)windowWidth; // making playerWidth always be equal to 20% of the width of the screen
		//dest.w = dest.h = (int)bulletWidth; //assigning width and the height of the bullet to bullet width

		SDL_RenderCopy(renderer, bulletTexture, NULL, &dest);
	};
};


void BulletManager::clean()
{
	SDL_DestroyTexture(this->bulletTexture);
};







