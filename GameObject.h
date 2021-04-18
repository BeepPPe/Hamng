
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "Window.h"

class GameObject
{

public:
    GameObject(const char* texturesheet, int x, int y, int h, int w);
    ~GameObject();


    void Render();

private:

    //toa do
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect scrRect, desRect;



};

#endif // GAME_OBJECT_H_
