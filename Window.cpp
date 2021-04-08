#include "Window.h"
#include "TextureManager.h"
#include "GameObject.h"

SDL_Texture* Background = NULL;
GameObject* hanger;

Window::Window()
{};
Window::~Window()
{};

void Window::init(const char* title, int xpos, int ypos, int width, int height, bool  fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        int flags = 0;
        if(fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        std::cout <<"Subsystem Initialized"<< std::endl;
        window = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
        if(window) std::cout << "Window created" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {

            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;

        Background = TextureManager::LoadTexture("assets/background.png", renderer);
        hanger = new GameObject("assets/hanger.png", renderer, 320, 240);

    } else isRunning = false;
}

void Window::handleEvents()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Window::update()
{
    hanger->Update();
}

void Window::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, Background, NULL, NULL);
    hanger->Render();
    SDL_RenderPresent(renderer);
}

void Window::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game clean" << std::endl;

}
