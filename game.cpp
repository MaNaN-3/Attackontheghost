#include"game.hpp"
#include "Ghost.hpp"
#include "SinGhost.hpp"
#include "Player.hpp"
#include<iostream>
#define ghostHeight 70
#define ghostWidth 70
#define resolutionX 1200
#define resolutionY 900
#define heroX resolutionX/2
#define heroY resolutionY/2

SDL_Texture* playerTex; 
SDL_Rect destR;
vector <Ghost*> ghosts;
Player *p;
SDL_Texture *backgroundTexture;
SDL_Surface *background=SDL_LoadBMP("background1.bmp");

void Game::hehe()
{
    cout<<"Funck"<<endl;
}

void Game::ghostHandler()
{
    SinGhost *g1 = new SinGhost(0,0,ghostHeight,ghostWidth,"ghost1.png",0.5,renderer);
    // SDL_Delay(1000);
    SinGhost *g2 = new SinGhost(0,heroY,ghostHeight,ghostWidth,"ghost1.png",0.5,renderer);
    // SDL_Delay(1000);
    SinGhost *g3 = new SinGhost(resolutionX-ghostWidth,0,ghostHeight,ghostWidth,"ghost1.png",0.5,renderer);

    ghosts.push_back(g1);
    ghosts.push_back(g2);
    ghosts.push_back(g3);

    p = new Player(heroX,heroY,80,80,"mario.png",renderer);
    p->update();
    p->animate();

}

Game:: Game(const char * title,int positionX,int positionY,int width,int height,bool fullscreen)
{
    windowWidth=width; windowHeight=height;
    cout<<windowWidth << " "<<windowHeight<<endl;
    int flag=0;
    if(fullscreen){
        flag=SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        cout<<"SDL is initialised\n";
        window=SDL_CreateWindow(title,positionX,positionY,width,height,flag);
        renderer=SDL_CreateRenderer(window,-1,0);
        SDL_SetRenderDrawColor(renderer,255,255,0,255); 
        
        // SDL_Texture *texture;
        backgroundTexture= SDL_CreateTextureFromSurface(renderer,background);
        isRunning=true;
    }

    else
    {
        isRunning=false;
    }  

    ghostHandler();
}

Game:: ~Game(){};

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    p->render();
    for(int i=0;i<ghosts.size();i++)
    {
        if(ghosts[i]!=NULL)
        {
            ghosts[i]->render();
        }
    }
    SDL_RenderPresent(renderer);
}

void Game::eventHandler()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning=false;
            break;
        case SDL_KEYDOWN:
            isRunning=false;
            break;
        default:
            break;
    }
}

bool Game::running()
{
    return isRunning;
}

void Game::update()
{
    for(int i=0; i<ghosts.size();i++)
    {
        if(ghosts[i]!=NULL)
        {
            bool hemlo=ghosts[i]->update();
            if(ghosts[i]->getInitialisedX()>resolutionX/2){
                ghosts[i]->animate("ghost2.png","ghost3.png");
            }
            else
                ghosts[i]->animate("ghost2.png","ghost3.bmp");
            if(hemlo==true)
            {
                ghosts[i]=NULL;
            }
        }
    }
    if(ghosts.size()==0){
        isRunning=false;
    }    
}