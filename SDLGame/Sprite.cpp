#include "Sprite.h"

//Constructors define what to do when creating an object of this class type
Sprite::Sprite()
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

Sprite::Sprite(SDL_Renderer* pRenderer, const char* textureFilename)
{
	rotation = 0;
	dst.x = 0;
	dst.y = 0;
	pImage = IMG_LoadTexture(pRenderer, textureFilename);
	SDL_QueryTexture(pImage, NULL, NULL, &dst.w, &dst.h);

	src.x = 0;
	src.y = 0;
	src.w = dst.w;
	src.h = dst.h;
}

void Sprite::draw(SDL_Renderer* pRenderer)
{
	SDL_RenderCopyEx(pRenderer, pImage, &src, &dst, rotation, nullptr, SDL_FLIP_NONE); // Draw our texture at the destination position, width, and size
}

void Sprite::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Sprite::moveBy(int x, int y)
{
	dst.x += x;
	dst.y += y;
}

void Sprite::setDimensions(int width, int height)
{
	dst.w = width;
	dst.h = height;
}

void Sprite::setRotation(double rotationDegrees)
{
	rotation = rotationDegrees;
}

void Sprite::cleanup()
{
	SDL_DestroyTexture(pImage);
}
