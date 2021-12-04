#include <bits/stdc++.h>
#include "Ghost.hpp"
#include "ExpGhost.hpp"
#define heroX 960
#include <cmath>


ExpGhost::ExpGhost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer):Ghost(x,y,height,width,image,x_vel,renderer)
{

}

bool ExpGhost::update()
{
    x+=x_vel;  y= 1500*exp(-x/500);
    destR.h=height; destR.w=width;
    destR.x=x; destR.y=y;

    if(abs(heroX-x)<960)
        return true;
    else
    {
        return false;
    }
}

void ExpGhost::animate(const char* image1,const char* image2)
{
    SDL_Surface* tmpSurface;

    if(((int)(x/20))%2==0)
        tmpSurface=IMG_Load(image1);
    else
        tmpSurface=IMG_Load(image2);

    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    SDL_Delay(4);
}