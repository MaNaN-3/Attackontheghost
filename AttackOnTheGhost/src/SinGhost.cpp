#include <bits/stdc++.h>
#include "../include/Ghost.hpp"
#include "../include/SinGhost.hpp"
#include"SDL_mixer.h"
#include <cmath>
#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX/2
#define heroY resolutionY/2

SinGhost::SinGhost(float x, float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer,string s):Ghost(x,y,height,width,image,x_vel,renderer,s)
{
    //counter=0;
    // SDL_RenderClear(renderer);
    //Ghost::render();
    //SDL_RenderPresent(renderer);
    // SDL_Delay(1000);
}

bool SinGhost::update(SDL_Rect playerRect,Player *p)
{ 
    if (destroyed == false) {
        counter += 5;
        if (initialisedX < resolutionX / 2)
        {
            x += x_vel;
            y = initialisedY + ((initialisedY - resolutionY / 2) / (initialisedX - resolutionX / 2)) * (x - initialisedX) + 100 * sin(2 * (2 * acos(0.0)) * (x) / 100);
        }
        else
        {
            x -= x_vel;
            y = initialisedY + ((initialisedY - resolutionY / 2) / (initialisedX - resolutionX / 2)) * (x - initialisedX) + 100 * sin(2 * (2 * acos(0.0)) * (x) / 100);
        }

        destR.h = height; destR.w = width;
        destR.x = x; destR.y = y;
    }

    int checker = counter/15;

    
    if ((checker) % 4 == 0)
    {
        srcR.x = 3;
        srcR.y = 3;
        srcR.w = 218;
        srcR.h = 252;
    }
    else if ((checker) % 4 == 1)
    {
        srcR.x = 238;
        srcR.y = 3;
        srcR.w = 243;
        srcR.h = 250;
    }
    else  if ((checker) % 4 == 2)
    {
        srcR.x = 3;
        srcR.y = 245;
        srcR.w = 233;
        srcR.h = 227;
    }
    else if ((checker) % 4 == 3)
    {
        srcR.x = 246;
        srcR.y = 240;
        srcR.w = 209;
        srcR.h = 247;
    }
    
    // dest1.x = x; dest1.y = y;

    // if(abs(heroX-x)<60)
    //     return true;
    // else
    //     return false;
    if (destroyed && (Bullet == NULL)) {
        Mix_Chunk* chunk = Mix_LoadWAV("Sound/bullet_fire.wav");
        Mix_PlayChannel(-1, chunk, 0);
        Bullet = new bullet(destR.x, destR.y, destR.h, destR.w, "images/fire.bmp", 40, renderer);
        //p->update(destroyed);
    }
   
    if(SDL_HasIntersection(&destR,&playerRect)) return true;
    return false;
}
