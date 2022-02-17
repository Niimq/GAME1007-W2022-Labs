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

int windowSizeX = 800; // Declaring an int and assigning it the value 800
int windowSizeY = 600;
const char* windowName = "Hello SDL";
SDL_Window* pWindow = nullptr; // Declaring a pointer to SDL_Window and assigning it the value nullptr
SDL_Renderer* pRenderer = nullptr;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
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

	SDL_Texture* pShipImage = IMG_LoadTexture(pRenderer, "Assets/playerShip1_blue.png");
	SDL_Rect shipRectDst;
	SDL_QueryTexture(pShipImage, NULL, NULL, &shipRectDst.w, &shipRectDst.h);
	shipRectDst.x = 400 - shipRectDst.w / 2;
	shipRectDst.y = 300 - shipRectDst.h / 2;

	//Really really basic game loop... forever
	while (true)
	{
		SDL_SetRenderDrawColor(pRenderer, 245, 180, 180, 255); // Select a color
		SDL_RenderClear(pRenderer); // Paint the canvas according to the last selected color

		shipRectDst.y = shipRectDst.y - 1;
		SDL_RenderCopy(pRenderer, pShipImage, NULL, &shipRectDst); // Draw our texture at the destination position, width, and size

		SDL_RenderPresent(pRenderer); // Show the canvas
		SDL_Delay(16); // Wait 16 ms between frames
	}

	getchar();

	//Cleanup
	SDL_DestroyTexture(pShipImage);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	std::cout << "bye!" << std::endl;
	return 0;
}