#include <bits/stdc++.h>
#include "Ghost.hpp"
#include "SinGhost.hpp"
#include <cmath>


SinGhost::SinGhost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer):Ghost(x,y,height,width,image,x_vel,renderer)
{

}

void SinGhost::update()
{
    x+=x_vel;  y=400+200*sin(2*(2 * acos(0.0))*x/500);
    cout<<x<<" "<<y<<endl;
    destR.h=height; destR.w=width;
    destR.x=x; destR.y=y;
}

void SinGhost::animate(const char* image1,const char* image2)
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