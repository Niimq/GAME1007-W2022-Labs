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
/*
A class in C++... defines a new Type. It is a blueprint that allows you to create many Objects of this Type. 
When you define a class, you can make variables of it as a new type

A class can be instantiated to create a new Object

A class contains data members and functions
the data members can belong to instances of the class
the functions can operate on that class

*/ 

//C++ functions
//C++ pointers
//SDL_Rect
//SDL_Texture
//SDL_Renderer
//SDL_Window
//nullptr
Game myGame;

/*
main
{
	game = Game();
	game.run();
	
	load()
	while(gameRunning)
	{
		game.input();
		game.update();
		game.draw();
	}
	cleanup();
}

load()
{
	ship1 =  Ship()
	ship1.setLocation(50,500)

	ship2 =  Sprite("ship2.png")
	ship2.setPosition(50,500)
}

update()
{
	ship1.update()
}

draw()
{
	ship1.draw();
}

*/



// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	myGame.run();


	Sprite myShip = Sprite(pRenderer, "Assets/playerShip3_red.png");
	myShip.setPosition(400, 600);

	Sprite myBackground = Sprite(pRenderer, "Assets/Backgrounds/purple.png");
	myBackground.setSize(800, 600);
	//SDL_Texture* background = IMG_LoadTexture(pRenderer, "Assets/Backgrounds/purple.png");
	

	float gameTimeSeconds = 0.0f;
	while (true)
	{
		//Update
		myShip.setPosition( 200 + sin(gameTimeSeconds * 0.15f) * 100,
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
	
	getchar();

	// Clean up
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);

	myShip.cleanup();
	myBackground.cleanup();

	return 0;
}