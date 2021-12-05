<<<<<<< HEAD
#include <bits/stdc++.h>
#include "Ghost.hpp"


Ghost::Ghost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer)
{
    this->x = x;this->y = y;
    this->height = height;this->width = width;
    this->image = image;
    this->x_vel = x_vel;
    this->renderer = renderer;
}

void Ghost::render()
{
    SDL_RenderCopy(renderer,playerTex,NULL,&destR);
}

void Ghost::update()
{
    x+=x_vel;  y++;
    destR.h=height; destR.w=width;
    destR.x=x; destR.y=y;
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
=======
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
    if(abs(heroX-x)<60)
        return true;
    else
        return false;
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
>>>>>>> b5ca5d4f23a7af9945d2eb8185a5af0730f24252
}