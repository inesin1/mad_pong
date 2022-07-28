//
// Game
//

//-----------------------
// gameMode:
//     0 - SinglePlayer
//     1 - MultiPlayer
//-----------------------

#ifndef MAD_PONG_GAME_H
#define MAD_PONG_GAME_H

#pragma once

//INCLUDE//
#include "include/nlohmann/json.hpp"
#include <map>
#include <fstream>
//EndInclude

using json = nlohmann::json;
using namespace std;

class Game {
private:
    map<string, string> getSettings();
public:
    Game(int gameMode);
};


#endif //MAD_PONG_GAME_H
