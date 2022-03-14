#include <iostream>
#include <SDL.h> 
#include <SDL_image.h>
#include "Sprites.h"
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
// In C++ A class is a new type which "encapsulates" data members and functions.
//C++ functions
//C++ pointers
//SDL_Rect
//SDL_Texture
//SDL_Renderer
//SDL_Window
//nullptr

int windowSizeX = 1000;
int windowSizeY = 770;
const char* windowName = "Space Cadet";
SDL_Window* pWindow = nullptr; //Declaring a pointer SDL_Window
SDL_Renderer* pRenderer = nullptr;
SDL_Texture* pShipimage;
SDL_Rect ShipRectDst, MonsterDst, pBackgroundDst, pMeteorDst, pLaserDst;

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
	
	SDL_Texture* pBackground;
	pBackground = IMG_LoadTexture(pRenderer, "Assets/Background.png");


	SDL_QueryTexture(pBackground, NULL, NULL, &pBackgroundDst.w, &pBackgroundDst.h);


	SDL_RenderCopy(pRenderer, pBackground, NULL, &pBackgroundDst);



	///////////////////Sprite of Obstacles///////////////
	////////////////////////////////////////////////////


	SDL_Texture* pMeteor;
	pMeteor = IMG_LoadTexture(pRenderer, "Assets/Meteors/meteorPruple_big2.png");

	SDL_QueryTexture(pMeteor, NULL, NULL, &pMeteorDst.w, &pMeteorDst.h);

	pMeteorDst.x = 700;
	pMeteorDst.y = 370;


	SDL_RenderCopy(pRenderer, pMeteor, NULL, &pMeteorDst);



	///////////////////SPRTIE OF SHIP///////////////////
	////////////////////////////////////////////////////



	pShipimage = IMG_LoadTexture(pRenderer, "Assets/playerShip.png");

	//it gets the information of weidth and height of  ship.image (pixels)


	ShipRectDst.w = 179;
	ShipRectDst.h = 155;

	ShipRectDst.x = 500 - ShipRectDst.w / 2;
	ShipRectDst.y = 650 - ShipRectDst.h / 2;

	SDL_RenderCopy(pRenderer, pShipimage, NULL, &ShipRectDst);

	/////////////////////////////////////////////
////////////////////LASER///////////////////

	SDL_Texture* pLaserimage;
	pLaserimage = IMG_LoadTexture(pRenderer, "Assets/Lasers/ShipLaser.png");

	SDL_QueryTexture(pLaserimage, NULL, NULL, &pLaserDst.w, &pLaserDst.h);

	pLaserDst.x = 495;
	pLaserDst.y = 500;

	SDL_RenderCopy(pRenderer, pLaserimage, NULL, &pLaserDst);

	SDL_RenderPresent(pRenderer); //Show the Canvas




	////////////////////////////////////////
	///////// SPRITES OF ENEMIES //////////




		SDL_Texture* pMonsterimage;
		pMonsterimage = IMG_LoadTexture(pRenderer, "Assets/Monsters.png");

		SDL_QueryTexture(pMonsterimage, NULL, NULL, &MonsterDst.w, &MonsterDst.h);

		MonsterDst.x = 255;
		MonsterDst.y = 110;

		Sprites anotherMonster = Sprites(pRenderer, "Assets/playerShipasaledition.png");
		anotherMonster.setPoisition(600, 300);
		anotherMonster.setDimensions(30, 40);



		while (true)
		{


			SDL_SetRenderDrawColor(pRenderer, 13, 10, 24, 0); //Select a color
			SDL_RenderClear(pRenderer); //paint the canvas accoring to the last selected color

			//drawing a ship

			anotherMonster.draw(pRenderer);
			anotherMonster.moveBy(0, -1);

			MonsterDst.y = MonsterDst.y - 1;
			SDL_RenderCopy(pRenderer, pMonsterimage, NULL, &MonsterDst);

			SDL_RenderPresent(pRenderer); // Show the canvas
			SDL_Delay(16); // Wait 16ms between frames
		}
	    
    


	getchar();

	//Cleanup
	SDL_DestroyTexture(pShipimage);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow (pWindow);
	std::cout << "bye!" << std::endl;
	return 0;
}