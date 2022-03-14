#include <iostream>
#include <SDL.h> 
#include <SDL_image.h>
#include "Sprites.h"
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
// In C++ A class is a new type which "encapsulates" data members and functions.
//C++ functions
//C++ pointers
//SDL_Rect
//SDL_Texture
//SDL_Renderer
//SDL_Window
//nullptr



// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	myGame = Game();
	myGame.run();
	
	SDL_Renderer* pRenderer = nullptr;
	SDL_Texture* pShipimage;
	SDL_Rect ShipRectDst, MonsterDst, pBackgroundDst, pMeteorDst, pLaserDst;
	
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
		SDL_RenderCopy(pRenderer, pMonsterimage, NULL, &MonsterDst);

		MonsterDst.x = 300;
		MonsterDst.y = 410;

	getchar();
	std::cout << "bye!" << std::endl;
	return 0;
}