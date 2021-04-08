#include "GameObject.h"
#include "TextureManager.h"

#include <SDL.h>

GameObject::GameObject(const char* texturesheet,int x,int y,int h,int w)
{

    objTexture = TextureManager::LoadTexture(texturesheet,Window::renderer);

    xpos = x;
    ypos = y;

    scrRect.h = h;
    scrRect.w = w;
}

void GameObject::Update()
{

    scrRect.x = 0;
    scrRect.y = 0;

    desRect.x = xpos;
    desRect.y = ypos;
    desRect.w = scrRect.w;
    desRect.h = scrRect.h;
}

void GameObject::Render()
{
    SDL_RenderCopy(Window::renderer, objTexture, &scrRect, &desRect);
}
