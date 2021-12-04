#include <bits/stdc++.h>
#include "Ghost.hpp"
#include "SinGhost.hpp"
#include <cmath>
#define heroX 960

SinGhost::SinGhost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer):Ghost(x,y,height,width,image,x_vel,renderer)
{
    counter=0;
}

bool SinGhost::update()
{
    x+=x_vel;  y=400+200*sin(2*(2 * acos(0.0))*(x-200)/500);
    destR.h=height; destR.w=width;
    destR.x=x; destR.y=y;

    if(abs(heroX-x)<60)
        return true;
    else
        return false;
}

void SinGhost::animate(const char* image1,const char* image2)
{
    if(abs(heroX-x)<960)
    {
        if(((int)(x/20))%2==0)
            tmpSurface=IMG_Load(image1);
        else
            tmpSurface=IMG_Load(image2);

        playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
        SDL_FreeSurface(tmpSurface);
    }
    else
    {    
        SDL_DestroyTexture(playerTex);
    }
}

// void SinGhost::animate(vector<string> imageArray){
//     SDL_Surface *tmpSurface;
//     if(counter==imageArray.size()){
//         counter=0;
//     }
//     string image=imageArray[counter];
//     const char * image_Name = image.c_str();
//     // const char *image_Name=const char *(imageArray[counter]);
    
//     tmpSurface=IMG_Load(image_Name);

//     playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
//     SDL_FreeSurface(tmpSurface);
//     SDL_Delay(4);
// }