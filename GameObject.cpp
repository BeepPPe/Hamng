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

void GameObject::Render()
{
    SDL_RenderCopy(Window::renderer, objTexture, &scrRect, &desRect);
}
