#pragma once
#include <SDL_image.h>

//Sprite class
//A sprite is an image with a position that can be moved around, and drawn to the screen




/*
A Sprite contains data for (data members):
- Image
- Position
- Size
- FlipState
- RotationDegrees

A Sprite can do (functions):
- moveBy(xOffset, yOffset)
- setPosition(x, y)
- setSize(width, height)
- setRotation(degrees)
- setImage(filename)

	ship2 =  Sprite(pRenderer, "ship2.png")
	ship2.setPosition(50,500)
	ship2.draw(pRenderer);
	ship2.moveBy(2, 0)

*/

class Sprite
{
private:
	SDL_Texture* pTexture;
	SDL_Rect src; // source rectangle for rendering. Represents the part of the texture to draw when rendering this sprite
	SDL_Rect dst; // destination rectangle for rendering. Represents where the sprite will be drawn on-screen, and how big it will be when drawn

public:
	//Constructors. Special functions used when creating an object of this class.
	Sprite(); // Default constructor
	Sprite(SDL_Renderer* pRenderer, const char* filename); // 

	//Member Functions. <return type><name>(<parameters>)
	//Modifier or 'setter' function (changes something about the object)
	void setPosition(int x, int y);
	void moveBy(int xOffset, int yOffset);
	void setSize(int width, int height);
	
	void draw(SDL_Renderer* pRenderer) const; // const after the function says it will not change anything

	void cleanup();
};

