#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

//Texture wrapper class
SDL_Surface* image = SDL_LoadBMP("bg.bmp");
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor , TTF_Font* gFont);

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};
x: 954 y: 775
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
// SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Rendered texture
LTexture gTextTexture1;
LTexture gTextTexture2;
LTexture gTextTexture3;
LTexture gTextTexture4;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* gFont)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if(textSurface == NULL)
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	
	//Return success
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow( "Front Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				 //Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void close()
{
	//Free loaded images
	gTextTexture1.free();
	gTextTexture2.free();
	gTextTexture3.free();
	gTextTexture4.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		SDL_Color textColor1 = {210, 105, 30, 255};
		SDL_Color textColor2 = {0, 255, 0, 255};
		SDL_Color textColor3 = {178, 34, 34, 255};
		SDL_Color textColor4 = {255, 165,0,255};
		
		TTF_Font* gFont1 = TTF_OpenFont("game.ttf", 52);
		if(gFont1 == NULL){
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		}

		if(!gTextTexture1.loadFromRenderedText("Attack On The Ghosts", textColor1, gFont1)){
			printf("Failed to render text texture!\n");
		}

		TTF_CloseFont(gFont1);
	    gFont1 = NULL;


		TTF_Font *gFont2 = TTF_OpenFont("game.ttf", 38);
		if(gFont2 == NULL){
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		}
		
		if(!gTextTexture2.loadFromRenderedText("START", textColor2, gFont2)){
			printf("Failed to render text texture!\n");
		}

		TTF_Font* gFont5 = TTF_OpenFont("game.ttf", 40);
		if (gFont5 == NULL)
		{
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());	
		}
		if(!gTextTexture4.loadFromRenderedText("Scoreboard", textColor4, gFont5)){
			printf("Failed to render text texture!\n");
		}

		TTF_CloseFont(gFont5);
	    gFont5 = NULL;
		
		
		if(!gTextTexture3.loadFromRenderedText("QUIT", textColor3, gFont2)){
			printf("Failed to render text texture!\n");
		}

		TTF_CloseFont(gFont2);
		gFont2 = NULL;


		//Main loop flag
		bool quit = false;
        bool main_game = false;

		//Event handler
		SDL_Event e;
	// 	gWindow = SDL_CreateWindow( "Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    //     if( gWindow == NULL )
    //     {
    //         printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    //     }
    //     else
    //     {
    //         //Get window surface
    //         gScreenSurface = SDL_GetWindowSurface( gWindow );
    //     }
	//     SDL_FreeSurface( gHelloWorld );
    // gHelloWorld = NULL;

    // //Destroy window
    // SDL_DestroyWindow( gWindow );
    // gWindow = NULL;
	


		//While application is running
		while(!quit)
		{
			//Handle events on queue
			while(SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				// SDL_FreeSurface(image);
				// SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
				// SDL_UpdateWindowSurface( gWindow );
				// SDL_Delay( 2000 );
				
				if(e.type == SDL_QUIT)
				{
					quit = true;
				}

                if(e.type == SDL_MOUSEBUTTONDOWN)
                {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    int k1 = (SCREEN_WIDTH - gTextTexture3.getWidth())/2;
                    int k2 = (SCREEN_WIDTH + gTextTexture3.getWidth())/2;
                    if((x>=k1) && (x<=k2) && (y>=750) && (y<=750+38))
                        quit = true;
                    
                    int m1 = (SCREEN_WIDTH - gTextTexture2.getWidth())/2;
                    int m2 = (SCREEN_WIDTH + gTextTexture2.getWidth())/2;
                    if((x>=m1) && (x<=m2) && (y>=300) && (y<=300+38))
                        main_game = true;      

                    printf("x: %d y: %d\n",x,y);              
                }
			}

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 30, 30, 30, 0xFF);
			SDL_RenderClear(gRenderer);

			//Render current frame
			gTextTexture1.render((SCREEN_WIDTH - gTextTexture1.getWidth()) / 2, 100);
			gTextTexture2.render((SCREEN_WIDTH - gTextTexture2.getWidth()) / 2, 300);
			gTextTexture4.render((SCREEN_WIDTH - gTextTexture4.getWidth()) / 2, 500);
			gTextTexture3.render((SCREEN_WIDTH - gTextTexture3.getWidth()) / 2, 750);
            // if(main_game == true)
            // {
            //      gTextTexture1.render((SCREEN_WIDTH - gTextTexture1.getWidth()) / 2, 0);
            // } 

			//Update screen
			SDL_RenderPresent( gRenderer );
		}
	}
    //Free resources and close SDL
	close();
	return 0;
}