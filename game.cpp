#include"game.hpp"
#include "Ghost.hpp"
#include "SinGhost.hpp"
#include "Player.hpp"
#include<iostream>
#define ghostHeight 70
#define ghostWidth 70
#define heroX 960

SDL_Texture* playerTex; 
SDL_Rect destR;
SinGhost *g;
Ghost *g1,*g2,*g3,*g4;
Player *p;


void Game::hehe(){
    cout<<"Funck"<<endl;
}
void Game::ghostHandler(){

    g1 = new SinGhost(1920,1080,70,70,"ghost1.png",0,renderer);
    p = new Player(880,460,80,80,"mario.png",renderer);

}

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

    ghostHandler();
}
Game:: ~Game(){};

void Game::render(){

    SDL_RenderClear(renderer);
    if(g1!=NULL)
    g1->render();
    p->render();
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
    if(g1!=NULL){
    bool hemlo=g1->update();
    g1->animate("ghost.png","ghost1.png");
    if(hemlo=false){
        g1=NULL;
    }
    }
    p->update();
    p->animate("mario2.png");
    
}