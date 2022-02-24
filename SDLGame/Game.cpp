#include "Game.h"
#include <SDL_image.h>

Game::Game()
{
	int flags = SDL_INIT_EVERYTHING;
	int rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC; //These are two integers representing settings combined with the | operator. This pattern you will see in other cases too

	//Getting SDL features booted up
	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		// Create the window
		pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);

		if (pWindow) // If window was created successfully
		{
			//Create SDL_Renderer object
			pRenderer = SDL_CreateRenderer(pWindow, -1, rendererFlags);

			if (pRenderer)
			{
				IMG_Init(IMG_INIT_PNG);
			}
		}
	}
}

void Game::run()
{
	bRunning = true;

	anotherShip = Sprite(pRenderer, "Assets/playerShip1_red.png");
	anotherShip.setPosition(300, 200);
	anotherShip.setRotation(180);

	//Really really basic game loop... forever
	while (bRunning)
	{
		input();

		update();

		draw();

		SDL_Delay(16); // Wait 16 ms between frames
	}

	cleanup();
}

void Game::input()
{
}

void Game::update()
{
	anotherShip.moveBy(0, 1);
}

void Game::draw()
{
	SDL_SetRenderDrawColor(pRenderer, 245, 180, 180, 255); // Select a color
	SDL_RenderClear(pRenderer); // Paint the canvas according to the last selected color

	//Drawing a ship
	anotherShip.draw(pRenderer);

	SDL_RenderPresent(pRenderer); // Show the canvas
}

void Game::quit()
{
	bRunning = false;
}

void Game::cleanup()
{	
	anotherShip.cleanup();
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
}
