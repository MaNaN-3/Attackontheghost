#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
// #include"Ghost.hpp"
class ExpGhost : public Ghost
{
public:
    ExpGhost(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer);
    bool update();
    void animate(const char *, const char *);
};
