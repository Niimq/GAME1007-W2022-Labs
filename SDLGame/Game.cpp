#include "Game.h"
#include <SDL_image.h>
#include <iostream>

Game::Game()
{

}

Game::Game(const char* windowName)
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

	float fixedDeltaTimeSeconds = 0.016; // seconds

	//Really really basic game loop... forever
	while (bRunning)
	{
		input();

		update(fixedDeltaTimeSeconds);

		draw();

		SDL_Delay(fixedDeltaTimeSeconds * 1000); // Wait 16 ms between frames
	}

	cleanup();
}

void Game::input()
{
	//SDL's input system works by "polling" devices
	SDL_Event lastInput;

	// & is the 'reference' operator. 
	//It gets the address of a variable i.e. &lastInput means "memory address of variable lastInput"
	while(SDL_PollEvent(&lastInput))
	{
		//pressing a button starts with going from up to down, then held, then down to up
		if (lastInput.type == SDL_KEYDOWN)
		{
			switch (lastInput.key.keysym.sym)
			{
			case(SDLK_w):
				//std::cout << "Up" << std::endl;
				isUpPressed = true;
				break;
			case(SDLK_d):
				//std::cout << "Right" << std::endl;
				isRightPressed = true;
				break;
			case(SDLK_s):
				//std::cout << "Down" << std::endl;
				isDownPressed = true;
				break;
			case(SDLK_a):
				//std::cout << "Left" << std::endl;
				isLeftPressed = true;
				break;
			}
		} else if (lastInput.type == SDL_KEYUP)
		{
			switch (lastInput.key.keysym.sym)
			{
			case(SDLK_w):
				isUpPressed = false;
				break;
			case(SDLK_d):
				isRightPressed = false;
				break;
			case(SDLK_s):
				isDownPressed = false;
				break;
			case(SDLK_a):
				isLeftPressed = false;
				break;
			}
		}
	}
}

void Game::update(const float deltaTime)
{
	float acceleration = 3500.0f;
	float deltaV = acceleration * deltaTime;

	if (isUpPressed)
	{
		anotherShip.velocity.y -= deltaV;
	}
	if (isRightPressed)
	{
		anotherShip.velocity.x += deltaV;
	}
	if (isDownPressed)
	{
		anotherShip.velocity.y += deltaV;
	}
	if (isLeftPressed)
	{
		anotherShip.velocity.x -= deltaV;
	}

	float damping = 56.25f * deltaTime;
	anotherShip.velocity.x *= damping;
	anotherShip.velocity.y *= damping;

	anotherShip.update(deltaTime);
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
