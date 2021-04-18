#ifndef __game_h__
#define __game_h__
#include <string>
#include "Window.h"
class Game
{

public:
    Game(SDL_Renderer* ren);
    ~Game();

    int MAX_BAD_GUESS = 7;
    std::string chooseWord(const std::string& fileName);
    bool contains(std::string word, char guess);





    std::string Vocabulary;
private:


};
#endif // __UTILITY_H__
