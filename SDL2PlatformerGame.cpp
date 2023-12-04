#include "GameLoop.h"
#include "Timer.h"

int main()
{
	GameLoop gameLoop = GameLoop();
	std::unique_ptr<Timer> globalTimer = std::unique_ptr<Timer>(new Timer());

	if (gameLoop.init() < 0) 
	{
		return 1;
	}

	/*SDL_Event event;*/

	const float deltaTime = 0.01f; // number the of times we refresh the game each second, which we set to 100 times for smooth physics
	float accumulator = 0.0f; // this is the point where within that 1 second we reach the timestep and the screen gets refreshed
	float currentTime = globalTimer->globalTimeInSeconds();
	while (gameLoop.gameRunning())
	{


		float newTime = globalTimer->globalTimeInSeconds();
		float frameTime = newTime - currentTime; // the amount of time it takes for a frame to complete

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= deltaTime) // if the time to refresh the image within the given frame has exceeded threshold to update it then we run this loop
		{
			while (SDL_PollEvent(gameLoop.getEventptr()))
			{
				if (gameLoop.getEvent().type == SDL_QUIT)
				{
					return false;
				};

				gameLoop.runEvents();

			};

			gameLoop.render(); // update with delta time

			accumulator -= deltaTime;
		};

		gameLoop.update(); // update without delta time
		
	};

	gameLoop.clean();

	
	return 0;
}