#include"game.hpp"
#include<iostream>
#define ghostHeight 70
#define ghostWidth 70

SDL_Texture* playerTex; 
SDL_Rect destR;
Game:: Game(const char * title,int positionX,int positionY,int width,int height,bool fullscreen){
    countX=0; countY=0;
    countZ=0;
    windowWidth=width; windowHeight=height;
        // cout<<"hehe";
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

    SDL_Surface* tmpSurface;
    if(countY%2==0)
        tmpSurface=IMG_Load("ghost1.png");
    else
        tmpSurface=IMG_Load("ghost.png");
    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);


    
}
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
    countX+=2;
    countY++;
    destR.h=ghostHeight;
    destR.w=ghostWidth;
    if(countX >windowWidth/2-ghostWidth){
        countX=0;
        countY=0;
    }
    destR.x=countX;
    destR.y=countY;
    // cout<<count<<endl;

    SDL_Surface* tmpSurface;
    countZ=countY/10;
    if(countZ%2==0)
        tmpSurface=IMG_Load("ghost1.png");
    else
        tmpSurface=IMG_Load("ghost.png");
    playerTex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    SDL_Delay(4);
}