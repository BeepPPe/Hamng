#include "Window.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"


Window *window = nullptr;

int main(int arg, const char * argv[])
{

    const int FPS =60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    window = new Window();
    window->init("HangMan",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 640,480,false);
    while (window->running())
    {
        frameStart = SDL_GetTicks();

        window->handleEvents();
        window->update();
        window->render();

        frameTime = SDL_GetTicks() -frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window->clean();

    return 0;
}
