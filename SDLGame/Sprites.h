#pragma once
#include <SDL_image.h>


	//A sprite is any image which live on the screen and can be moved about

	// Declaring new class called Sprite
	// Sprites sjpi;d cpmtaom fimtiomality to load an image and have its own position


	// It should contain :
	// texture (image)
	// postioon
	//


	// It can do :
	// load an image 
	// draw itself at a location
	// set the position of the sprite
	// set the rotation

	//Sprites Ship myShip = Sprites("ship.png")
	// //myShip.setPosition(50, 100) // set position gloabally on the screen
	//myShip.draw(pRenderer)
    //myship.move(2,0) // move horizontally to the right relative to its current position
    //myShip.Dimensions(60, 60) //set size in pixels
    //myShip.setScale(2.5, 2.5) // scale sprite by 2.5x


//2-dimensional vector
struct Vector2
{
	float x;
	float y;
};




class Sprites
{
private:
	//Data members
	SDL_Texture* pImage = nullptr;
	SDL_Rect dst; //destination rectangle, representing position and size of the sprite
	SDL_Rect src; //source rectangle, representing which part of the texture to draw this sprite from

public:
	//Constructors
	Sprites(); // default constructor
	Sprites (SDL_Renderer* pRenderer, const char* texturefilename ); // constructor with parameters for the image file

	//Declaring Member functions <return type> <na me> (<parameters>)
	void draw(SDL_Renderer* pRenderer);


	//setter
	void setPoisition(int x, int y);
	void moveBy(int x, int y);
	void setDimensions(int width, int height);
};

