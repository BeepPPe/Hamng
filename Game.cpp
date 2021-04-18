#include "Game.h"
#include <ctime>
#include <vector>
#include "Window.h"
#include <fstream>


Game::Game(SDL_Renderer* ren)
{
    srand(time(0));
    Vocabulary = chooseWord("assets/WordList.txt");

}
Game::~Game(){}
std::string Game::chooseWord(const std::string & fileName)
{
    std::vector<std::string> vocab;
    std::ifstream file(fileName);
    if (!file.is_open())
        return "";

    while (!file.eof()) {
        std::string line;
        getline(file, line);
        if (file && !line.empty())
            vocab.push_back(line);
    }

    int n = vocab.size();
    std::cout << "vocabulary size = " << n << std::endl;
    return n > 0 ? vocab[rand() % n] : "";
}

bool Game::contains(std::string word, char guess)
{
    return (word.find(guess) != std::string::npos);
}


