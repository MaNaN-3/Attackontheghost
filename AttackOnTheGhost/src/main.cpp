#include<iostream>
#include <fstream>
#include"../include/game.hpp"

#define resolutionX 1920
#define resolutionY 1080
#define heroX resolutionX/2
#define heroY resolutionY/2

using namespace std;

Game *game=nullptr;



int main(){
    int sc=0;
    const int FPS=60;
    const int frameDelay=100/FPS;
    vector<string> scores;
    fstream my_file;
    my_file.open("scores.txt", ios::in);
    string tp;
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    while(getline(my_file, tp))
    {
        scores.push_back(tp);
    }
    sort(scores.begin(), scores.end(), greater<string>());
    
    if(scores.size() != 0)
        sc = stoi(scores[0]);
    
    fstream file;
    file.open("scores.txt", ios::app);    Uint32 frameStart;
    int frameTime;
    Uint32 substracter;
    game = new Game("manan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resolutionX, resolutionY, true,sc);
    game->highscore = sc;
    cout << "main: " << game->highscore << endl;
    while(game->running()){
        frameStart=SDL_GetTicks();
        game->eventHandler();
        game->update();
        
        if(game->score>game->highscore)
        {
            game->highscore = game->score;
        }
        game->render();
        frameTime=frameStart-SDL_GetTicks();
        if(frameDelay>frameTime){
            substracter = (frameDelay - frameTime) * (0.8);
            SDL_Delay((frameDelay-frameTime)-substracter);
            //cout << (frameDelay - frameTime) / 100 << endl;
        }
        if (game->power == 0) {
            
            game->power = 5;
            
            break;

         }
    }
    if(game->power==0)
    SDL_Delay(4000);
    
    file << game->score << endl;

    return 0;
}