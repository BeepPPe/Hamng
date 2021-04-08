#pragma once

#include "Window.h"

class GameObject
{

public:
    GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:

    //toa do
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect scrRect, desRect;
    SDL_Renderer* renderer;


};
