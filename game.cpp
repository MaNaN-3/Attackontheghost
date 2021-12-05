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
vector <Ghost*> ghosts;
Player *p;


void Game::hehe()
{
    cout<<"Funck"<<endl;
}

void Game::ghostHandler()
{
    SinGhost *g1 = new SinGhost(200,200,70,70,"ghost1.png",5,renderer);
    SinGhost *g2 = new SinGhost(200,800,70,70,"ghost1.png",5,renderer);
    SinGhost *g3 = new SinGhost(1600,200,70,70,"ghost1.png",5,renderer);
    SinGhost *g4 = new SinGhost(1600,800,70,70,"ghost1.png",5,renderer);
    SinGhost *g5 = new SinGhost(1600,500,70,70,"ghost1.png",5,renderer);
    SinGhost *g6 = new SinGhost(200,500,70,70,"ghost1.png",5,renderer);
    ghosts.push_back(g1);ghosts.push_back(g2);ghosts.push_back(g3);ghosts.push_back(g4);ghosts.push_back(g5);ghosts.push_back(g6);
    p = new Player(880,460,80,80,"mario.png",renderer);
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
    for(int i=0;i<ghosts.size();i++)
    {
        if(ghosts[i]!=NULL)
        {
            ghosts[i]->render();
        }
    }
    p->render();
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
            ghosts[i]->animate("ghost.png","ghost1.png");
            if(hemlo==true)
            {
                ghosts[i]=NULL;
            }
        }
    }
    p->update();
    p->animate();    
}