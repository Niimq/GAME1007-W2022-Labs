#include <iostream>
#include <SDL.h> 
#include <SDL_image.h>
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
//C++ functions
//C++ pointers
//SDL_Rect
//SDL_Texture
//SDL_Renderer
//SDL_Window
//nullptr

int windowSizeX = 800;
int windowSizeY = 600;
const char* windowName = "Hello SDL";
SDL_Window* pWindow = nullptr; //Declaring a pointer SDL_Window
SDL_Renderer* pRenderer = nullptr;
SDL_Texture* pShipimage;
SDL_Rect ShipRectDst;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
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

	SDL_SetRenderDrawColor(pRenderer, 285, 100, 100, 255); //Select a color
	SDL_RenderClear(pRenderer); //paint the canvas accoring to the last selected color


	pShipimage = IMG_LoadTexture(pRenderer, "Assets/playerShip1_blue.png");
	

	SDL_QueryTexture(pShipimage, NULL, NULL, &ShipRectDst.w, &ShipRectDst.h); //it gets the information of weidth and height of  ship.image (pixels)

	ShipRectDst.x = 400 - ShipRectDst.w / 2;
	ShipRectDst.y = 550 - ShipRectDst.h / 2;


	SDL_RenderCopy(pRenderer, pShipimage, NULL, &ShipRectDst);

	SDL_RenderPresent(pRenderer); //Show the Canvas


	getchar();
	return 0;
}