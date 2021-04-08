#ifndef __game_h__
#define __game_h__
#include <string>
#include <fstream>

std::string chooseWord(const std::string& fileName);
bool contains(std::string word, char guess);

#endif // __UTILITY_H__
