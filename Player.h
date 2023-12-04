#pragma once
#include <SDL.h>
#include <SDL_IMAGE.h>
#include <iostream>
#include "Vector2Float.h"
#include "Timer.h"
#include "TileMap.h"

class Player
{

public:
	Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y);

	void init();
	void render();
	void update();
	void clean();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void handleSprite();
	bool isPlayerOnGround();

	const int defaultScreenWidth = 1280; // these are the height and width of the screen at which assets are being positioned
	const int defaultScreenHeight = 720;

	const float newWidthDividedByDefaultX = (float)windowWidth / (float)defaultScreenWidth; /* how many times do we need to multiply the pos of */
	const float newHeightDividedByDefaultY = (float)windowHeight / (float)defaultScreenHeight; 	/*an asset to get it back to its place after changing the resolution */
	
	void gravity();

	void jump();

	bool getFacingRight()
	{
		return facingRight;
	};
	void setFacingRight(bool newFacingRight)
	{
		facingRight = newFacingRight;
	};

	bool getFacingLeft()
	{
		return facingLeft;
	};
	void setFacingLeft(bool newFacingLeft)
	{
		facingLeft = newFacingLeft;
	};

	bool getMovingLeft()
	{
		return movingLeft;
	};
	void setMovingLeft(bool newMovingLeft)
	{
		movingLeft = newMovingLeft;
	};

	bool getMovingRight()
	{
		return movingRight;
	};
	void setMovingRight(bool newMovingRight)
	{
		movingRight = newMovingRight;
	};

	bool getMovingUp()
	{
		return movingUp;
	};
	void setMovingUp(bool newMovingUp)
	{
		movingUp = newMovingUp;
	};

	bool getMovingDown()
	{
		return movingDown;
	};
	void setMovingDown(bool newMovingDown)
	{
		movingDown = newMovingDown;
	};

	void setFrameTime(int newFrameTime)
	{
		frameTime = newFrameTime;
	};

	bool getIsShooting()
	{
		return isShooting;
	}
	void setIsShooting(bool newIsShooting)
	{
		isShooting = newIsShooting;
	}

	bool getIsJumping()
	{
		return isJumping;
	}
	void setIsJumping(bool newIsJumping)
	{
		isJumping = newIsJumping;
	}

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
	};

	float getPlayerWidth()
	{
		return playerWidth;
	}

	SDL_Rect getPortion()
	{
		return portion;
	};

	float getConstantSpeed()
	{
		return constantSpeed;
	};

	void playerCollisionPlatformOne(); // this a fast collision that I will use for now, and later I will implment my bounding box collision

	void playerCollisionPlatformTwo();

private:
	float x = 0.0f;
	float y = 0.0f;
	const float constantSpeed = 3.0f;
	float playerWidth;
	const float percentageNumber = 10.0f;
	float percentagePlayerWidthComparedToScreen = percentageNumber / 100.0f;; //20%
	int frameTime = 0;
	float newFrameTime;

	std::unique_ptr<Timer> globalTimer = std::unique_ptr<Timer>(new Timer());

	SDL_Surface* imagePlayer = nullptr;

	int windowWidth = 0;
	int windowHeight = 0;

	bool movingLeft = false;
	bool movingRight = false;
	bool movingUp = false;
	bool movingDown = false;

	bool facingRight = true;
	bool facingLeft = false;

	bool isShooting = false;

	bool isJumping = false;

	const float platformHeight = 240.0f; // until I implement my bounding box collision, I will use hardcoded numbers for collisions





	SDL_Rect portion = SDL_Rect(); //created a rectangle object to copy the entire texture to just a portion of the renderer
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	

};

