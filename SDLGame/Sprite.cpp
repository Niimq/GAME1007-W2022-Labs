#include "Sprite.h"

Sprite::Sprite()
{
	pTexture = nullptr;
	src.x = 0;
	src.y = 0;
	src.w = 0;
	src.h = 0;

	dst.x = 0;
	dst.y = 0;
	dst.w = 0;
	dst.h = 0;
}

Sprite::Sprite(SDL_Renderer* pRenderer, const char* filename) : Sprite()
{
	pTexture = IMG_LoadTexture(pRenderer, filename);
	SDL_QueryTexture(pTexture, NULL, NULL, &dst.w, &dst.h);
	src.w = dst.w;
	src.h = dst.h;
}

void Sprite::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Sprite::moveBy(int xOffset, int yOffset)
{
	dst.x += xOffset;
	dst.y += yOffset;
}

void Sprite::setSize(int width, int height)
{
	dst.w = width;
	dst.h = height;
}

void Sprite::draw(SDL_Renderer* pRenderer) const
{
	SDL_RenderCopy(pRenderer, pTexture, &src, &dst); // Draw texture
}

void Sprite::cleanup()
{
	SDL_DestroyTexture(pTexture);
}
