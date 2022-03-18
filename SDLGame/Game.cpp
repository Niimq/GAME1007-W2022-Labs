#include <iostream>
#include "Game.h"
#include <SDL_image.h>
#include "Sprites.h"
Sprites anotherMonster;
Game::Game()
{
	
	int flags = SDL_INIT_EVERYTHING;
	int rendererflags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC; //These are two integers representing setting combined with
																//-with the | operator. This patter you will see in other cases too.
	//getting everything booted up
	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		// Create the window
		pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);

		if (pWindow) //Window was created succesfully.
		{
			//Create SDL_Render object
			pRenderer = SDL_CreateRenderer(pWindow, -1, rendererflags);


			if (pRenderer)
			{
				IMG_Init(IMG_INIT_PNG);
			}

		}

	}

	SDL_Renderer* pRenderer = nullptr;
	SDL_Rect ShipRectDst, MonsterDst, pBackgroundDst, pMeteorDst, pLaserDst;


}

void Game::run()
{
	bRunning = true;

	Sprites anotherMonster;
	anotherMonster	= Sprites(pRenderer, "Assets/playerShip.png");
	anotherMonster.setPoisition(20, 700);
	anotherMonster.setRotation(180);

	while (bRunning)
	{
		input();

		update();
			
		draw();


		SDL_Delay(20); // Wait 16ms between frames
	}

	cleanup();

}

void Game::input()
{
}

void Game::update()
{
	anotherMonster.moveBy(2, -1);
	MonsterDst.y += -2.5;
	MonsterDst.x += 1;
}

void Game::draw()
{

	SDL_Texture* pMonsterimage;
	pMonsterimage = IMG_LoadTexture(pRenderer, "Assets/Monsters.png");

	SDL_QueryTexture(pMonsterimage, NULL, NULL, &MonsterDst.w, &MonsterDst.h);
	SDL_RenderCopy(pRenderer, pMonsterimage, NULL, &MonsterDst);

	MonsterDst.x = 300;
	MonsterDst.y = 410;




	SDL_SetRenderDrawColor(pRenderer, 13, 10, 24, 0); //Select a color
	SDL_RenderClear(pRenderer); //paint the canvas accoring to the last selected color

	//background details
	SDL_Texture* pBackground;
	pBackground = IMG_LoadTexture(pRenderer, "Assets/Background.png");


	SDL_QueryTexture(pBackground, NULL, NULL, &pBackgroundDst.w, &pBackgroundDst.h);


	SDL_RenderCopy(pRenderer, pBackground, NULL, &pBackgroundDst);


	//drawing a ship

	anotherMonster.draw(pRenderer);
	

	
	SDL_RenderCopy(pRenderer, pMonsterimage, NULL, &MonsterDst);

	SDL_RenderPresent(pRenderer); // Show the canvas
}

void Game::quit()
{
	bRunning = false;

}

void Game::cleanup()
{
	anotherMonster.cleanup();
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
}
