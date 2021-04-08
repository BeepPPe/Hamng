#include "Window.h"
#include "TextureManager.h"
#include "GameObject.h"

LTexture Alphabet;
SDL_Rect AlphabeticClips[27];
SDL_Texture* Background = NULL;
GameObject* hanger;

SDL_Renderer* Window::renderer = nullptr;

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

        Background = TextureManager::LoadTexture("assets/background.png",renderer);
        hanger = new GameObject("assets/hanger.png",350, 134, 251, 91);

        if (!Alphabet.loadFromFile("assets/Alphabet.png"))
        {
            printf("Fail to load Alphabet");
        }
        else {
            AlphabeticClips[26].x = 26;
            AlphabeticClips[26].y = 64;
            AlphabeticClips[26].w = 13;
            AlphabeticClips[26].h = 16;

            Alphabet.TextureRender(0,0,&AlphabeticClips[26]);

            SDL_RenderPresent(renderer);
        }

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
