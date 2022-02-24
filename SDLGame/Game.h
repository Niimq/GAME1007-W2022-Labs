#pragma once
#include <SDL.h> 

class Game
{
	int windowSizeX = 800; // Declaring integer called windowSizeX, assigning it the value 800
	int windowSizeY = 600;
	const char* windowName = "Hello SDL";
	SDL_Window* pWindow = nullptr; // Declaring a SDL_Window* (pointer to an object of type SDL_Window) called pWindow, assigning it the value nullptr
	SDL_Renderer* pRenderer = nullptr;
	bool bIsRunning = false;

public:
	Game();

	int run();
	void input();
	void update();
	void draw();
	void quit();
	void cleanup();
};

