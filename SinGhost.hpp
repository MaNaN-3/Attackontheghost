#include<bits/stdc++.h>
#include"SDL2/SDL.h"
#include<SDL_image.h>
// #include"Ghost.hpp"
class SinGhost : public Ghost{
    public:
        SinGhost(float x,float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer);
        void update();
        void animate(const char*, const char*);
};
