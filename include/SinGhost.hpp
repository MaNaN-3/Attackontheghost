#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>

class SinGhost : public Ghost
{
public:
        SDL_Surface *tmpSurface;
        SinGhost(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer,string p);
        bool update();
        void animate(const char *, const char *);
        // Manan Changes:
        //  void animate(vector<string>);
        int counter;
};
