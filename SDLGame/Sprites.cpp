#include "Sprites.h"

//Constructors define what to do when creating an object of this class type
Sprites::Sprites()
{
	pImage = nullptr;
	rotation = 0;
	dst.x = 0;
	dst.y = 0;
	dst.w = 0;
	dst.h = 0;
	src.x = 0;
	src.y = 0;
	src.w = 0;
	src.h = 0;



}

Sprites::Sprites(SDL_Renderer* pRenderer, const char* texturefilename)
{
	rotation = 0;
	dst.x = 0;
	dst.y = 0;
	pImage = IMG_LoadTexture(pRenderer, texturefilename);
	SDL_QueryTexture(pImage, NULL, NULL, &dst.w, &dst.h);

	src.x = 0;
	src.y = 0;
	src.w = dst.w;
	src.h = dst.h;

}

void Sprites::draw(SDL_Renderer* pRenderer)
{
	SDL_RenderCopyEx(pRenderer, pImage, &src, &dst, rotation, nullptr, SDL_FLIP_NONE);
}

void Sprites::setPoisition(int x, int y)
{
	dst.x = x;
	dst.y = y;

}

void Sprites::moveBy(int x, int y)
{
	dst.x += x;
	dst.y += y;
}


void Sprites::setDimensions(int width, int height)
{
	dst.w = width;
	dst.h = height;
}

void Sprites::setRotation(double rotationDegrees)
{
	rotation = rotationDegrees;
}

void Sprites::cleanup()
{
	SDL_DestroyTexture(pImage);
}

