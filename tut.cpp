#include<iostream>
#include"game.hpp"

using namespace std;

Game *game=nullptr;

int main(){
    game=new Game();
    const int FPS=60;
    const int frameDelay=100/FPS;

    Uint32 frameStart;
    int frameTime;

    game->init("manan",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,0);

    cout<<"hehe";
    while(game->running()){
        // cout<<"hehe";
        frameStart=SDL_GetTicks();
        game->eventHandler();
        game->update();
        game->render();
        frameTime=frameStart-SDL_GetTicks();
        if(frameDelay>frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }
    // game->clean();
    return 0;
}

// int main(){
//     cout<<"hehe\n";
//     Game *game=new Game();
//     cout<<"hehe\n";

//     game->init("manan",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
//     cout<<"hehe\n";
//     return 0;
// }