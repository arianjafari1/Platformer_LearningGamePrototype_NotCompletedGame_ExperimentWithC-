#include "GameLoop.h"


int GameLoop::init()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL2!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow(
		"hello_sdl2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		std::cout << "Could not initialise window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Could not initialise renderer!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 144, 238, 144));
	SDL_UpdateWindowSurface(window);

	soundPlayer = std::unique_ptr<Sound>(new Sound()); //instantiate a sound player

	globalTimer = std::unique_ptr<Timer>(new Timer()); //using a smart pointer, I create an instance of the Timer

	//array of floor tiles, 37 tiles at 35 distance from each
	floorTiles = { new TileMap(renderer, screenWidth, screenHeight, 0.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 35.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 70.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 105.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 140.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 175.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 210.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 245.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 280.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 315.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 350.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 385.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 420.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 455.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 490.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 525.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 560.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 595.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 630.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 665.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 700.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 735.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 770.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 805.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 840.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 875.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 910.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 945.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 980.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1015.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1050.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1085.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1120.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1155.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1190.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 1225.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 1260.0f * newWidthDividedByDefaultX, floorTilePosY * newHeightDividedByDefaultY) };
	for (int i = 0; i < floorTiles.size(); ++i)
	{
		floorTiles[i]->init();
	};
	std::cout << "Floor tiles number: " << floorTiles.size() << std::endl;



	platformOne = { new TileMap(renderer, screenWidth, screenHeight, 250.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 285.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 320.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 355.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY), 
					new TileMap(renderer, screenWidth, screenHeight, 390.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 425.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY), };
	

	for (int i = 0; i < platformOne.size(); ++i)
	{
		platformOne[i]->init();
	};

	platformTwo = { new TileMap(renderer, screenWidth, screenHeight, 800.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 835.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 870.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 905.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 940.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY),
					new TileMap(renderer, screenWidth, screenHeight, 975.0f * newWidthDividedByDefaultX, platformOneTilePosY * newHeightDividedByDefaultY), };

	for (int i = 0; i < platformTwo.size(); ++i)
	{
		platformTwo[i]->init();
	};

	player = new Player(renderer, screenWidth, screenHeight, playerXpos/* * newWidthDividedByDefaultX*/, playerYpos * newHeightDividedByDefaultY);
	player->init();

	enemyOne = std::unique_ptr<Enemy>(new Enemy(renderer, screenWidth, screenHeight, 300.0f * newWidthDividedByDefaultX, 340.0f * newHeightDividedByDefaultY));
	enemyOne->init();

	enemyTwo = std::unique_ptr<Enemy>(new Enemy(renderer, screenWidth, screenHeight, 700.0f * newWidthDividedByDefaultX, 540.0f * newHeightDividedByDefaultY));
	enemyTwo->init();

	bulletManager = new BulletManager(this->renderer, this->player, screenWidth);
	bulletManager->init();

	fontRenderer = std::unique_ptr<FontRenderer>(new FontRenderer(renderer, screenWidth, screenHeight, 600.0f * newWidthDividedByDefaultX, 0.0f * newHeightDividedByDefaultY)); //using a smart pointer, I create an instance of the FontRenderer class
	fontRenderer->init();

	fontRendererMoveControls = std::unique_ptr<FontRenderer>(new FontRenderer(renderer, screenWidth, screenHeight, 0.0f * newWidthDividedByDefaultX, 0.0f * newHeightDividedByDefaultY));;
	fontRendererMoveControls->init();

	fontRendererEscapeKey = std::unique_ptr<FontRenderer>(new FontRenderer(renderer, screenWidth, screenHeight, 0.0f * newWidthDividedByDefaultX, 40.0f * newHeightDividedByDefaultY));;
	fontRendererEscapeKey->init();

	fontRendererJumpandShoot = std::unique_ptr<FontRenderer>(new FontRenderer(renderer, screenWidth, screenHeight, 0.0f * newWidthDividedByDefaultX, 80.0f * newHeightDividedByDefaultY));;
	fontRendererJumpandShoot->init();


	return 0;
};



bool GameLoop::gameRunning()
{
	return true;
}


void GameLoop::update() // this is an update function that is frame-rate dependent, nothing physics should be put here
{
	playSoundEffects();
};

void GameLoop::runEvents()
{
	if (event.type == SDL_KEYDOWN)
	{
		handleInputKeyDown(event.key.keysym.scancode);
	};

	if (event.type == SDL_KEYUP)
	{
		handleInputKeyUp(event.key.keysym.scancode);
	}

	
};


void GameLoop::render() //this now acts as a fixed update, and update with delta time applied to it, so it's frame-rate in independent
{
	SDL_RenderClear(renderer);

	globalTime = (int)globalTimer->globalTimeInSeconds();
	std::cout << globalTime << std::endl;
	std::string globalTimeString = std::to_string(globalTime);

	for (int i = 0; i < floorTiles.size(); ++i)
	{
		/*floorTilePosX = posXdistanceTiles * i;*/
		floorTiles[i]->render();
	};
	for (int i = 0; i < platformOne.size(); ++i)
	{
		platformOne[i]->render();
	};
	for (int i = 0; i < platformTwo.size(); ++i)
	{
		platformTwo[i]->render();
	};

	
	enemyOne->render();
	enemyTwo->render();
	player->render();

	movePlayer(); //function to move player based on boolean

	bulletManager->render();

	fontRenderer->render(globalTimeString);

	fontRendererMoveControls->render("A and D to move");
	fontRendererEscapeKey->render("Escape Key to exit game");
	fontRendererJumpandShoot->render("Space to jump and F to shoot");

	

	SDL_RenderPresent(renderer);
};

void GameLoop::clean()
{
	fontRenderer->clean();
	fontRendererMoveControls->clean();
	fontRendererEscapeKey->clean();
	fontRendererJumpandShoot->clean();
	delete player;
	for (int i = 0; i < floorTiles.size(); ++i)
	{
		delete floorTiles[i];
	};
	for (int i = 0; i < platformOne.size(); ++i)
	{
		delete platformOne[i];
	};
	for (int i = 0; i < platformTwo.size(); ++i)
	{
		delete platformTwo[i];
	};
	bulletManager->clean();
	SDL_DestroyWindow(window);
	SDL_Quit();
};



void GameLoop::handleInputKeyDown(SDL_Scancode& keyScanCode) //method that handles input being defined
{

	switch (keyScanCode)
	{
	case SDL_SCANCODE_D:
		player->setMovingRight(true);
		player->setFacingLeft(false);
		player->setFacingRight(true);
		
		break;
	case SDL_SCANCODE_A:
		player->setMovingLeft(true);
		player->setFacingRight(false);
		player->setFacingLeft(true);
		break;
	case SDL_SCANCODE_F:
		player->setIsShooting(true);
		soundPlayer->PlaySound(Sounds::BLASTERSHOT);
		break;
	case SDL_SCANCODE_SPACE:
		player->setIsJumping(true);
		break;
	case SDL_SCANCODE_W:
		player->setMovingUp(true);
		break;
	case SDL_SCANCODE_S:
		player->setMovingDown(true);
		break;
	case SDL_SCANCODE_ESCAPE:
		SDL_Quit();
		break;
	};

	bulletManager->processInput(player->getIsShooting());

};

void GameLoop::handleInputKeyUp(SDL_Scancode& keyScanCode) //method that handles input being defined
{

	switch (keyScanCode)
	{
	case SDL_SCANCODE_D:
		player->setMovingRight(false);
		break;
	case SDL_SCANCODE_A:
		player->setMovingLeft(false);
		break;
	case SDL_SCANCODE_SPACE:
		player->setIsJumping(false);
		break;
	case SDL_SCANCODE_F:
		player->setIsShooting(false);
		break;
	};
};

void GameLoop::moveRight()
{
	player->moveRight();
};

void GameLoop::moveLeft()
{
	player->moveLeft();
};


void GameLoop::movePlayer()
{
	switch (player->getMovingRight())
	{
	case true:
		moveRight();
		player->setFrameTime(frameTimeSprite);
		++frameTimeSprite;
		break;
	case false:
		frameTimeSprite = 0;
		break;
	}

	switch (player->getMovingLeft())
	{
	case true:
		moveLeft();
		player->setFrameTime(frameTimeSprite);
		++frameTimeSprite;
		break;
	}

}



void GameLoop::playSoundEffects()
{
	
	if (player->isPlayerOnGround() && player->getMovingRight() || player->isPlayerOnGround() && player->getMovingLeft())
	{
		soundPlayer->PlaySound(Sounds::WALKING);
	}

	if ((player->getIsJumping()))
	{
		soundPlayer->PlaySound(Sounds::JUMPING);
	}
};