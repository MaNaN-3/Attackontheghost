#include "include/Ghost.hpp"
#define heroX 960

Ghost::Ghost(float x, float y, int height, int width, string image, float x_vel, SDL_Renderer *renderer, string p)
{
    this->x = x;
    this->y = y;
    this->initialisedX = x;
    this->initialisedY = y;
    this->height = height;
    this->width = width;
    this->image = image;
    this->x_vel = x_vel;
    this->renderer = renderer;
    this->s = p;
}

void Ghost::render()
{
    if (TTF_Init() < 0)
    {
        cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
    }

    font = TTF_OpenFont("font.ttf", 24);
    if (!font)
    {
        cout << "Failed to load font: " << TTF_GetError() << endl;
    }

    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
}

bool Ghost::update()
{
    x += x_vel;
    y++;
    destR.h = height;
    destR.w = width;
    destR.x = x;
    destR.y = y;
    if (abs(heroX - x) < 60)
        return true;
    else
        return false;
}

void Ghost::animate(const char *image1, const char *image2)
{
    SDL_Surface *tmpSurface;

    SDL_Color textColor = {0, 0, 0, 0xFF};
    // gInputTextTexture.loadFromRenderedText(s.c_str(),textColor);

    if (((int)(y / 10)) % 2 == 0)
        tmpSurface = IMG_Load(image1);
    else
        tmpSurface = IMG_Load(image2);

    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    SDL_Delay(4);
}