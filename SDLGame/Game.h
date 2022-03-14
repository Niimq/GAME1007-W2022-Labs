#pragma once
#include <SDL.h> 
#include "Sprites.h"
//This class will handle creating the basic game loop ad is where we will keep most things don't need to be global
//It will also handle cleanup


class Game
{
	int windowSizeX = 1000;
	int windowSizeY = 770;
	const char* windowName = "Space Cadet";
	SDL_Window* pWindow = nullptr; //Declaring a pointer SDL_Window
	SDL_Renderer* pRenderer = nullptr;
	SDL_Texture* pShipimage;
	SDL_Rect ShipRectDst, MonsterDst, pBackgroundDst, pMeteorDst, pLaserDst;
	bool bRunning = true;

public:
	//Constructor
	Game();


	//Game loop functions
	void run();


	void input();
	void update();
	void draw();

	void quit();

	void cleanup();
};

