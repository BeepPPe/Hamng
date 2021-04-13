#include "Window.h"
#include "TextureManager.h"
#include "GameObject.h"


LTexture Alphabet;
SDL_Rect AlphabeticClips[27];
SDL_Texture* Background = NULL;
GameObject* hanger;
LTexture PlayButton;
SDL_Rect PlayButtonClip[2];

//TTF_Font *gFont = NULL;

LTexture word;

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




        }
        //button
        if (!PlayButton.loadFromFile("assets/PlayButton.png"))
        {
            printf("Fail to load PlayButton");
        } else
        {
            PlayButtonClip[0].x = 0;
            PlayButtonClip[0].y = 43;
            PlayButtonClip[0].w = 140;
            PlayButtonClip[0].h = 43;
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

    SDL_RenderPresent(renderer);
}

void Window::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, Background, NULL, NULL);
    hanger->Render();

    Alphabet.TextureRender(0, 0, 4, &AlphabeticClips[26]);
    PlayButton.TextureRender( 44, 412, 1.25, &PlayButtonClip[0]);



    gFont = TTF_OpenFont("assets/font.ttf", 30);
    SDL_Color textColor = { 0, 0, 0 };
    if( !word.loadFromRenderedText( "The quick brown fox jumps over the lazy dog", textColor ) )
		{
			printf( "Failed to render text texture!\n" );

		}
    word.TextRender(640/2,480/2);

    SDL_RenderPresent(renderer);
}

void Window::clean()
{
    Alphabet.free();
    PlayButton.free();
    word.free();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    TTF_Quit();
    IMG_Quit();
    std::cout << "Game clean" << std::endl;

}
