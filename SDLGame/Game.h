#pragma once
#include <SDL.h> 
#include "Sprite.h"

class Game
{
	int windowSizeX = 800; // Declaring integer called windowSizeX, assigning it the value 800
	int windowSizeY = 600;
	const char* windowName = "Hello SDL";
	SDL_Window* pWindow = nullptr; // Declaring a SDL_Window* (pointer to an object of type SDL_Window) called pWindow, assigning it the value nullptr
	SDL_Renderer* pRenderer = nullptr;
	bool bIsRunning = false;

	Sprite myShip;
	Sprite myBullet;
	Sprite myBackground;

	float gameTime = 0.0f; // seconds since start of game
	float fixedDeltaTime = 0.016f; // time between frames 0.016 == 1/60

	bool isUpPressed	= false;
	bool isDownPressed	= false;
	bool isLeftPressed	= false;
	bool isRightPressed	= false;

public:
	Game();

	int run();
	void input();
	void update(const float deltaTime);
	void draw();
	void quit();
	void cleanup();
};

