#include "Sprites.h"

//Constructors define what to do when creating an object of this class type
Sprites::Sprites()
{
	pImage = nullptr;
	dst.x = 0;
	dst.y = 0;
	dst.w = 0;
	dst.h = 0;
	src.x = 0;
	src.y = 0;
	src.w = dst.w;
	src.h = dst.h;



}

Sprites::Sprites(SDL_Renderer* pRenderer, const char* texturefilename)
{
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
	SDL_RenderCopy(pRenderer, pImage, &src, &dst);
}

void Sprites::setPoisition(int x, int y)
{
	dst.x = x;
	dst.y = y;

}

void Sprites::moveBy(int x, int y)
{
	dst.x = x;
	dst.y = y;
}


void Sprites::setDimensions(int width, int height)
{
	dst.w = width;
	dst.h = height;
}

