#include"game.hpp"
#include "Ghost.hpp"
#include "SinGhost.hpp"
#include<iostream>
#define ghostHeight 70
#define ghostWidth 70

SDL_Texture* playerTex; 
SDL_Rect destR;
SinGhost *g;
Ghost *g1;
Game:: Game(const char * title,int positionX,int positionY,int width,int height,bool fullscreen){
    windowWidth=width; windowHeight=height;
    cout<<windowWidth << " "<<windowHeight<<endl;
    int flag=0;
    if(fullscreen){
        flag=SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout<<"SDL is initialised\n";

        window=SDL_CreateWindow(title,positionX,positionY,width,height,flag);
        renderer=SDL_CreateRenderer(window,-1,0);
        SDL_SetRenderDrawColor(renderer,255,255,0,255); 
        isRunning=true;
    }

    else{
        isRunning=false;
    };  

    g = new SinGhost(0,360,70,70,"images/ghost.png",3.5,renderer);
    g1 = g;
}
Game:: ~Game(){};

void Game::render(){

    SDL_RenderClear(renderer);
    g1->render();
    SDL_RenderPresent(renderer);
}

void Game::eventHandler(){

    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
        case SDL_KEYDOWN:
            isRunning=false;
        default:
            break;
    }

}

bool Game::running(){
    return isRunning;
}

void Game::update(){
    g1->update();
    g1->animate("ghost.png","ghost1.png");
    
}