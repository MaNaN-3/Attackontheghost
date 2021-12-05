#include <bits/stdc++.h>
#include "Player.hpp"


Player::Player(float x, float y, int height, int width, string image, SDL_Renderer* renderer)
{
    this->x = x; this->y = y;
    this->height = height; this->width = width;
    this->image = image;
    this->renderer = renderer;
}

void Player::render()
{
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
        // SDL_Delay(4);
}
void Player::update()
{
    destR.h = height; destR.w = width;
    destR.x = x; destR.y = y;
}

void Player::animate(const char* image1,const char* image2)
{
    SDL_Surface* tmpSurface;
    tmpSurface = IMG_Load(image1);
    //if (Colllison) {
        // new image
        //delay
    //}
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

}