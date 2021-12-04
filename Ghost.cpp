#include <bits/stdc++.h>
#include "Ghost.hpp"
#define heroX 960


Ghost::Ghost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer)
{
    this->x = x;this->y = y;
    this->initialisedX=x;
    this->initialisedY=y;
    this->height = height;this->width = width;
    this->image = image;
    this->x_vel = x_vel;
    this->x_vel=(heroX-x)*0.00364;
    // this->x_vel=3.5;
    this->renderer = renderer;
}

void Ghost::render()
{
    SDL_RenderCopy(renderer,playerTex,NULL,&destR);
}

bool Ghost::update()
{
    x+=x_vel;  y++;
    destR.h=height; destR.w=width;
    destR.x=x; destR.y=y;
    if(abs(initialisedX-x)<960)
        return true;
    else{
        return false;
    }
}

void Ghost::animate(const char* image1,const char* image2)
{
    SDL_Surface* tmpSurface;

    if(((int)(y/10))%2==0)
        tmpSurface=IMG_Load(image1);
    else
        tmpSurface=IMG_Load(image2);

    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    SDL_Delay(4);
}