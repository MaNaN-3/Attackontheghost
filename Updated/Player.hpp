#include<bits/stdc++.h>
#include"SDL.h"
#include<SDL_image.h>

using namespace std;
class Player
{
protected:
    float x, y;
    int height, width;
    string image;
    SDL_Rect destR;
    SDL_Texture* playerTex;
    SDL_Renderer* renderer;
public:
    Player(float x, float y, int height, int width, string image, SDL_Renderer* renderer);
    float get_x() { return x; }
    float get_y() { return y; }
    int get_height() { return height; }
    int get_width() { return width; }
    void render();
    void update();
    void animate(const char* image1 = "ghost.png");
};