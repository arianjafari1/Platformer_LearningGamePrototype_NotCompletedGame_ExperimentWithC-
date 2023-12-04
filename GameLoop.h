#pragma once

#include <iostream>
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <vector> //dynamic array
#include "Player.h"
#include "FontRenderer.h"
#include "Timer.h"
#include "TileMap.h"
#include "BulletManager.h"
#include "Sound.h"
#include "BoundingBoxCollision.h"
#include "Enemy.h"

	const int screenWidth = 1280;
	const int screenHeight = 720;
	
	const int defaultScreenWidth = 1280; // these are the height and width of the screen at which assets are being positioned
	const int defaultScreenHeight = 720;

class GameLoop
{
public:
	int init();

	bool gameRunning();
	void update();
	void render();
	void handleInputKeyDown(SDL_Scancode &keyScanCode); //method to process key-down events
	void handleInputKeyUp(SDL_Scancode& keyScanCode); //method to process key-up events
	void runEvents(); //function to run events in the fixed update loop
	void moveRight();
	void moveLeft();
	void movePlayer(); // function to move the player
	void playSoundEffects();

	SDL_Event& getEvent()
	{
		return event;
	}

	SDL_Event* getEventptr()
	{
		return &event;
	}



	void clean();


private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Event event;
	int globalTime;

	Player* player = nullptr;
	BulletManager* bulletManager = nullptr;

	std::unique_ptr<Timer> globalTimer;

	std::unique_ptr<FontRenderer> fontRenderer;
	std::unique_ptr<FontRenderer> fontRendererMoveControls;
	std::unique_ptr<FontRenderer> fontRendererEscapeKey;
	std::unique_ptr<FontRenderer> fontRendererJumpandShoot;

	std::unique_ptr<Sound> soundPlayer;

	std::unique_ptr<Enemy> enemyOne;
	std::unique_ptr<Enemy> enemyTwo;
	


	float newWidthDividedByDefaultX = (float)screenWidth / (float)defaultScreenWidth; /* how many times do we need to multiply the pos of */
	float newHeightDividedByDefaultY = (float)screenHeight / (float)defaultScreenHeight; 	/*an asset to get it back to its place after changing the resolution */

	float playerXpos = 0.0f;
	float playerYpos = 500.0f;

	const int floorTilePosY = 685; //the default position Y for the floor tile
	const int platformOneTilePosY = 480; //the default position Y for the platform one tile
	const int posXdistanceTiles = 35; // this is the distance between tiles on the x axis

	float frameTimeSprite;
	
	std::vector<TileMap*> floorTiles;
	std::vector<TileMap*> platformOne;
	std::vector<TileMap*> platformTwo;



};