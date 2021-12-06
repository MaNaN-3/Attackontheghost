#include <iostream>
#include "include/game.hpp"

#define resolutionX 1920
#define resolutionY 1080
#define heroX 960
#define heroY 540

using namespace std;

Game *game = nullptr;

int main()
{
    game = new Game("manan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resolutionX, resolutionY, 1);
    const int FPS = 60;
    const int frameDelay = 100 / FPS;

    Uint32 frameStart;
    int frameTime;

    while (game->running())
    {
        frameStart = SDL_GetTicks();
        game->eventHandler();
        game->update();
        game->render();
        frameTime = frameStart - SDL_GetTicks();
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}