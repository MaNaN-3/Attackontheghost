#include<iostream>
#include"game.hpp"

#define resolutionX 1200
#define resolutionY 900
#define heroX resolutionX/2
#define heroY resolutionY/2

using namespace std;

Game *game=nullptr;



int main(){
    game=new Game("manan",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,resolutionX,resolutionY,0);
    const int FPS=60;
    const int frameDelay=100/FPS;

    Uint32 frameStart;
    int frameTime;

    while(game->running()){
        frameStart=SDL_GetTicks();
        game->eventHandler();
        game->update();
        game->render();
        frameTime=frameStart-SDL_GetTicks();
        if(frameDelay>frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }
    return 0;
}