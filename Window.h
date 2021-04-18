
#ifndef SDL_main_h_
#define SDL_main_h_

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

class Window{

public:
    Window();
    ~Window();

    void init(const char* title, int xpos, int ypos, int with, int height, bool  fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };



    static SDL_Renderer* renderer; //window renderer
private:
    bool isRunning;
    SDL_Window* window; //Window rendering


};

#endif //SDL_main_h_
