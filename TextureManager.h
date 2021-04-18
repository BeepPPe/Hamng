#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include "Window.h"
#include <SDL_ttf.h>

class TextureManager
{

public:
    static SDL_Texture* LoadTexture (const char* fileNAme, SDL_Renderer* ren);
};

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
        //Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void TextureRender( int x, int y, float scale, SDL_Rect* clip = NULL);

		//color
        void setColor( Uint8 red, Uint8 green, Uint8 blue );
        //Set blending
        void setBlendMode( SDL_BlendMode blending );
        //Set alpha modulation
		void setAlpha( Uint8 alpha );
        //Renders texture at given point
		void TextRender( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
		//Image dimensions
		int mWidth;
		int mHeight;
};

#endif // TEXTURE_MANAGER_H_
