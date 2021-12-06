#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL_image.h>

using namespace std;

class Game
{
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int countX, countY, countZ;
    int windowWidth, windowHeight;
    // String_check* stringcheck; //Declaring String_check 
    vector<string> all_strings;

public:
    void ghostHandler();
    Game(const char *title, int positionX, int positionY, int width, int height, bool fullscreen);

    void init(const char *title, int positionX, int positionY, int width, int height, bool fullscreen);

    void update();
    void render();
    void clean();
    void eventHandler();
    bool running();
    void hehe();

    ~Game();
};