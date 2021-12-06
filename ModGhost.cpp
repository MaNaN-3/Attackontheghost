#include "include/Ghost.hpp"
#include "include/ModGhost.hpp"
#define heroX 960
#include <cmath>

ModGhost::ModGhost(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer) : Ghost(x, y, height, width, image, x_vel, renderer)
{
}

bool ModGhost::update()
{
    x += x_vel;
    y = abs(x - 1000);
    destR.h = height;
    destR.w = width;
    destR.x = x;
    destR.y = y;

    if (abs(heroX - x) < 60)
        return true;
    else
    {
        return false;
    }
}

void ModGhost::animate(const char *image1, const char *image2)
{
    SDL_Surface *tmpSurface;

    if (((int)(x / 20)) % 2 == 0)
        tmpSurface = IMG_Load(image1);
    else
        tmpSurface = IMG_Load(image2);

    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    SDL_Delay(4);
}