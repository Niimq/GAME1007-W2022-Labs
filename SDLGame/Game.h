#pragma once
#include <SDL.h> 
#include "Sprite.h"
//This class will handle creating the basic game loop and is where we will keep most things that don't need to be global
//It will also handle cleanup

class Game
{
	int windowSizeX = 800; // Declaring an int and assigning it the value 800
	int windowSizeY = 600;
	const char* windowName = "Hello SDL";
	SDL_Window* pWindow = nullptr; // Declaring a pointer to SDL_Window and assigning it the value nullptr
	SDL_Renderer* pRenderer = nullptr;
	bool bRunning = false;

	Sprite anotherShip;

	bool isUpPressed = false;
	bool isRightPressed = false;
	bool isDownPressed = false;
	bool isLeftPressed = false;

public:
	//Constructor
	Game();
	Game(const char* windowName);

	//Game loop functions
	void run();

	void input();
	void update(const float deltaTime);
	void draw();

	void quit();

	void cleanup();
};

