#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>
using namespace std;

class Ghost
{
protected:
    float x, y, initialisedX, initialisedY;
    int height, width;
    string image;
    float x_vel;
    SDL_Rect destR;
    SDL_Texture *playerTex;
    SDL_Renderer *renderer;
    string s;
    TTF_Font *font;

public:
    Ghost(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer,string p);
    float get_x() { return x; }
    float get_y() { return y; }
    int get_height() { return height; }
    int get_width() { return width; }
    float get_xvel() { return x_vel; }
    void render();
    virtual bool update();
    virtual void animate(const char *image1 = "ghost1.png", const char *image2 = "ghost.png");
    // virtual void animate(vector<string> hehe);
};
