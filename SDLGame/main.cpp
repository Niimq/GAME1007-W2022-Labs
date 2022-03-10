#include <iostream>
#include <SDL.h> 
#include <SDL_image.h>
#include "Sprite.h"
#include "Game.h"

// We need to figure out how to...
//1.	get SDL header files (.h files) to be included in this project so we can call its functions in the source code
//2.	get SDL precompiled libraries (.lib files) to be linked in this project so when we compile our code it can connect with SDL's compiled code!
//3.	get SDL dynamically linked libraries to connect so that our when our application runs, it can call SDL's functions
//4.	load a texture
//5		create a game loop
//6.	create a window object and a renderer object
//7.	render images to the window

//Things to look up:
//C++ Classes and objects
// A class in C++ is a new Type which "encapsulates" data members and functions
//
// 
//C++ functions
//C++ pointers
//SDL_Rect
//SDL_Texture
//SDL_Renderer
//SDL_Window
//nullptr

Game myGame;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	myGame = Game();
	myGame.run();

	//Really really basic game loop... forever
	while (true)
	{
		myGame.draw();
	}

	getchar();
	myGame.cleanup();
	std::cout << "bye!" << std::endl;
	return 0;
}