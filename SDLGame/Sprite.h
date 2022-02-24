#pragma once
#include <SDL_image.h>

// A sprite is any image which lives on the screen and can be moved about
//Sprite should contain functionality to load an image, and have its own position

//It should contain:
// texture (image)
// position
// size
// rotation

//It can do:
// load an image
// draw itself at a location
// set the size of the sprite
// set the position of the sprite
// set the rotation

//Sprite myShip = Sprite("ship.png")
//myShip.setPosition(50, 600) // set position globally on the screen
//myShip.draw(pRenderer)
//myShip.move(2,0) // move horizontally to the right relative to its current position
//myShip.setDimensions(60, 60) //set size in pixels
//myShip.setScale(2.5, 2.5) //scale sprite by 2.5x
//myShip.setRotation(180)


//2-dimensional vector
struct Vector2
{
	float x;
	float y;
};


//Declaring a new class called Sprite
class Sprite
{
private:
	//Data members
	SDL_Texture* pImage = nullptr;
	SDL_Rect dst; //destination rectangle, representing position and size of the sprite
	SDL_Rect src; //source rectangle, representing which part of the texture to draw this sprite from
	//a double is short for double-precision floating-point number. float is short for floating point number
	double rotation;


public:
	//Constructors
	Sprite(); // default constructor
	Sprite(SDL_Renderer* pRenderer, const char* textureFilename); // constructor with parameters for the image file

	//Declaring Member functions <return type><name>(<parameters>)
	void draw(SDL_Renderer* pRenderer);

	//setters, or modifiers
	void setPosition(int x, int y);
	void moveBy(int x, int y);
	void setDimensions(int width, int height);
	void setRotation(double rotationDegrees);

	//getters
	SDL_Point getPosition();
};

