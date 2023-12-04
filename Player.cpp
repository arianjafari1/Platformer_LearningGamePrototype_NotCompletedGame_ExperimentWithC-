#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight, float _x, float _y)
{
	renderer = sdlRenderer;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	x = _x;
	y = _y;
};

void Player::init()
{
	imagePlayer = IMG_Load("assets/sprites/1Trooper_player_Idle.png");
	if (imagePlayer == nullptr)
	{
		std::cout << "Could not load image!" << std::endl;
		return;
	};
	texture = SDL_CreateTextureFromSurface(renderer, imagePlayer);
}

void Player::render()
{
	handleSprite();
	isPlayerOnGround();

	portion.x = (int)x; //set pos on axis X to the x from the header file
	portion.y = (int)y; //set pos on axis Y to the y from the header file
	
	playerWidth = percentagePlayerWidthComparedToScreen * (float)windowWidth; // making playerWidth always be equal to 20% of the width of the screen
	portion.w = portion.h = (int)playerWidth; //assigning width and the height of the player to player width
	 //= (int)playerWidth; // the reason why playerHeight is also assigned playerWidth is so we don't have a stretched player
	
// function to copy texture to our current renderer
	SDL_RenderCopy(renderer, texture, NULL, &portion); /*first parameters are targer renderer and source texture, third one is the portion of texture that we want to copy,
	 and the fourth one is the portion of the screen to target (if we apply NULL to the last to it targets the whole render)  */
	playerCollisionPlatformOne();
	playerCollisionPlatformTwo();
	gravity();
	jump();

};

void Player::update()
{


};



void Player::clean()
{

};



void Player::handleSprite()
{

	newFrameTime = (float)frameTime * 0.01f; // the delta time for the game is 0.01, so if we multiply i by that we should get normal seconds
	/*std::cout << newFrameTime << std::endl;*/
	if (movingRight == true && newFrameTime >= 0.5f && newFrameTime < 0.8f)
	{
		imagePlayer = IMG_Load("assets/sprites/2Trooper_player_Walk.png");
		texture = SDL_CreateTextureFromSurface(renderer, imagePlayer);

	}
	else if (movingRight == true && newFrameTime >= 0.8f && newFrameTime < 1.3f)
	{
		imagePlayer = IMG_Load("assets/sprites/3Trooper_player_Walk.png");
		texture = SDL_CreateTextureFromSurface(renderer, imagePlayer);

	}
	else if (movingRight == true && newFrameTime >= 1.3f && newFrameTime < 1.5f)
	{
		imagePlayer = IMG_Load("assets/sprites/4Trooper_player_Walk.png");
		texture = SDL_CreateTextureFromSurface(renderer, imagePlayer);

	}
	else if (movingRight == true && newFrameTime >= 1.5f && newFrameTime <= 1.8f)
	{
		imagePlayer = IMG_Load("assets/sprites/3Trooper_player_Walk.png");
		texture = SDL_CreateTextureFromSurface(renderer, imagePlayer);
	}
	else if (movingRight == true && newFrameTime >= 1.8f)
	{
		frameTime = 0;
	}
	else
	{
		imagePlayer = IMG_Load("assets/sprites/1Trooper_player_Idle.png");
		texture = SDL_CreateTextureFromSurface(renderer, imagePlayer);
		frameTime = 0;
	};

}

void Player::gravity()
{
	if (isPlayerOnGround() == false)
	{
		y += 2;
	}
	
};

void Player::moveRight()
{
	if (x + (float)portion.w >= (float)windowWidth) /* portion x + portion.w is the pos of the player on x axis
										  + the size of the player on the x axis (width), so check for collison on the right */
	{
		x = (float)windowWidth - (float)portion.w; //so if condition met, then we collide and stop the player
	}
	else
	{
		x += constantSpeed; //otherwise we allow the player to keep moving right
	};
};


void Player::moveLeft()
{
	if (x <= (float)windowWidth - (float)windowWidth) /* x is the pos of the player on x axis
										and windowWidth - windowWidth will always give us 0 */
	{
		x = (float)windowWidth - (float)windowWidth; //so if condition met, then we collide and stop the player by setting the Width pos to 0
	}
	else
	{
		x -= constantSpeed; //otherwise we allow the player to keep moving left
	};
};

void Player::jump()
{
	if (isJumping)
	{
		y -= 7;
	}
		

};

bool Player::isPlayerOnGround()
{
	if (y + (float)portion.h >= (float)windowHeight - 38.4f) /* portion y + portion.h is the pos of the player on y axis
										  + the size of the player on the y axis (height), so check for collison on the bottom */
	{
		return true;
	}
	else
	{
		return false;
	};
}

void Player::playerCollisionPlatformOne() // this a fast collision that I will use for now, and later I will implment my bounding box collision
{
	if (y + (float)portion.h >= (float)windowHeight - platformHeight &&
		x + (float)portion.w >= (float)windowWidth / 4.5f && x <= (float)windowWidth - 830.0f &&
		isPlayerOnGround() == false)
										  
	{
		y = (float)windowHeight - platformHeight - (float)portion.h; //so if condition met, then we collide and stop the player
	}
	else
	{

	}

};

void Player::playerCollisionPlatformTwo() // this a fast collision that I will use for now, and later I will implment my bounding box collision
{
	if (y + (float)portion.h >= (float)windowHeight - platformHeight &&
		x + (float)portion.w >= (float)windowWidth / 1.55f && x <= (float)windowWidth - 290.0f &&
		isPlayerOnGround() == false)

	{
		y = (float)windowHeight - platformHeight - (float)portion.h; //so if condition met, then we collide and stop the player
	}
	else
	{

	}

};