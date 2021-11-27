#include"game.hpp"
#include<iostream>

SDL_Texture* playerTex; 
SDL_Rect destR;
Game:: Game(){count=0; countY=0;};
Game:: ~Game(){};

void Game::init(const char * title,int positionX,int positionY,int width,int height,bool fullscreen){

    // cout<<"hehe";
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

    SDL_Surface* tmpSurface;
    if(countY%2==0)
        tmpSurface=IMG_Load("ghost1.png");
    else
        tmpSurface=IMG_Load("ghost.png");
    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);


}
void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,playerTex,NULL,&destR);
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
    // SDL_Delay(10);
    count++;
    // if(count>600)
    //     count=0;
    destR.h=100;
    destR.w=100;
    // county++;
    if(count>250){
        count=0;
    }
    destR.x=count;
    destR.y=count;
    cout<<count<<endl;
    
    SDL_Surface* tmpSurface;
    countY=count/10;
    if(countY%2==0)
        tmpSurface=IMG_Load("ghost1.png");
    else
        tmpSurface=IMG_Load("ghost.png");
    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
}