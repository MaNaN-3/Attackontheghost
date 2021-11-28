#include<bits/stdc++.h>
#include"SDL2/SDL.h"
#include<SDL_image.h>

using namespace std;
class Ghost
{
    protected:
        float x,y;
        int height,width;
        string image;
        float x_vel;
        SDL_Rect destR;
        SDL_Texture* playerTex;
        SDL_Renderer *renderer;
    public:
        Ghost(float x,float y,int height,int width,string image,float x_vel,SDL_Renderer *renderer);
        float get_x(){ return x; }
        float get_y(){ return y; }
        int get_height(){ return height; }
        int get_width(){ return width; }
        float get_xvel(){ return x_vel; }
        void render();
        virtual void update();
        void animate(const char* image1="ghost1.png",const char* image2="ghost.png");
};