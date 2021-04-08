#include "Window.h"

class TextureManager
{

public:
    static SDL_Texture* LoadTexture (const char* fileNAme, SDL_Renderer* ren);
};
