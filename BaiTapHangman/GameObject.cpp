#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
}

void GameObject::Update()
{


    scrRect.h = 640;
    scrRect.w = 420;
    scrRect.x = 0;
    scrRect.y = 0;

    desRect.x = xpos;
    desRect.y = ypos;
    desRect.w = scrRect.w * 2;
    desRect.h = scrRect.h * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &scrRect, &desRect);
}
