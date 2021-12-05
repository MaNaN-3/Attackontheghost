<<<<<<< HEAD
#include<bits/stdc++.h>
#include"SDL2/SDL.h"
#include<SDL_image.h>

class SinGhost:public Ghost
{
    public:
        SinGhost(float x,float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer);
        void update();
        void animate(const char*, const char*);
};
=======
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
>>>>>>> 2a494eac7e89cc5294d93f7ef783e5ad9e9a58b9
