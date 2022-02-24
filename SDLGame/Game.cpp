#include "Game.h"
#include <SDL_image.h>
#include <iostream>

Game::Game()
{
}

int Game::run()
{
	// Setting up SDL features...
	int flags = SDL_INIT_EVERYTHING;
	if (SDL_Init(flags) != 0) // if initialized SDL correctly...
	{
		std::cout << "SDL failed to initialize" << std::endl;
		return -1;
	}

	// Create the window
	pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);
	if (pWindow == NULL) // If 
	{
		std::cout << "window failed to create" << std::endl;
		return -1;
	}

	// The renderer is needed to draw to the screen
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (pRenderer == NULL)
	{
		std::cout << "renderer failed to create" << std::endl;
		return -1;
	}

	int whatWasInitialized = IMG_Init(IMG_INIT_PNG);
	if (whatWasInitialized != IMG_INIT_PNG)
	{
		std::cout << "SDL_img failed to initialize" << std::endl;
		return -1;
	}


	while (bIsRunning)
	{
		//Update
		myShip.setPosition(200 + sin(gameTimeSeconds * 0.15f) * 100,
			400 + cos(gameTimeSeconds * 0.15f) * 100
		);

		//Render
		SDL_SetRenderDrawColor(pRenderer, 255, 200, 200, 255); // Choose a color
		SDL_RenderClear(pRenderer); // Clear canvas to color chosen

		myBackground.draw(pRenderer);
		myShip.draw(pRenderer);

		SDL_RenderPresent(pRenderer); // Make updated canvas visible on screen

		SDL_Delay(16);
		gameTimeSeconds += 0.16;
	}





	return 0;
}

void Game::input()
{
}

void Game::update()
{
}

void Game::draw()
{
}

void Game::quit()
{
}

void Game::cleanup()
{
}
