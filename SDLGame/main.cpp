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

int windowSizeX = 800; // Declaring integer called windowSizeX, assigning it the value 800
int windowSizeY = 600;
const char* windowName = "Hello SDL";
SDL_Window* pWindow = nullptr; // Declaring a SDL_Window* (pointer to an object of type SDL_Window) called pWindow, assigning it the value nullptr
SDL_Renderer* pRenderer = nullptr;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	// Setting up SDL features...
	int flags = SDL_INIT_EVERYTHING;
	if (SDL_Init(flags) != 0) // if initialized SDL correctly...
	{
		std::cout << "SDL failed to initialize" << std::endl;
		return -1;
	}

	// Create the window
	pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);
	if (pWindow == NULL) // If 
	{
		std::cout << "window failed to create" << std::endl;
		return -1;
	}

	// The renderer is needed to draw to the screen
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (pRenderer == NULL)
	{
		std::cout << "renderer failed to create" << std::endl;
		return -1;
	}

	int whatWasInitialized = IMG_Init(IMG_INIT_PNG);
	if (whatWasInitialized != IMG_INIT_PNG)
	{
		std::cout << "SDL_img failed to initialize" << std::endl;
		return -1;
	}

	//Load texture
	SDL_Texture* shipTexture = IMG_LoadTexture(pRenderer, "Assets/playerShip3_red.png");
	SDL_Rect shipTextureDst;
	SDL_QueryTexture(shipTexture, NULL, NULL, &shipTextureDst.w, &shipTextureDst.h);
	shipTextureDst.x = 400 - shipTextureDst.w / 2;
	shipTextureDst.y = 600 - shipTextureDst.h;
	//shipTextureDst.w = 60;
	//shipTextureDst.h = 40;

	SDL_Texture* background = IMG_LoadTexture(pRenderer, "Assets/Backgrounds/purple.png");

	float gameTimeSeconds = 0.0f;
	while (true)
	{
		//Update
		shipTextureDst.y = 200 + sin(gameTimeSeconds * 0.15f) * 100;//shipTextureDst.y - 2; //Make ship move
		shipTextureDst.x = 400 + cos(gameTimeSeconds * 0.15f) * 100;

		//Render
		SDL_SetRenderDrawColor(pRenderer, 255, 200, 200, 255); // Choose a color
		SDL_RenderClear(pRenderer); // Clear canvas to color chosen

		SDL_RenderCopy(pRenderer, background, NULL, NULL); // Render background image to cover entire screen
		SDL_RenderCopy(pRenderer, shipTexture, NULL, &shipTextureDst); // Draw texture

		SDL_RenderPresent(pRenderer); // Make updated canvas visible on screen

		SDL_Delay(16);
		gameTimeSeconds += 0.16;
	}
	
	getchar();

	// Clean up
	SDL_DestroyTexture(shipTexture);
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);

	return 0;
}