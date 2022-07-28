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
#include "SFML/Graphics.hpp"
#include <map>
#include <fstream>

#include "Engine.h"
#include "Bat.h"
#include "Ball.h"
//EndInclude

//Using
using json = nlohmann::json;
using namespace std;
//EndUsing

class Game {
private:
    //Const
    const Vector2f G_DEFAULT_BAT_L_POS = Vector2f(50, Engine::W_HALF_HEIGHT);
    const Vector2f G_DEFAULT_BAT_R_POS = Vector2f(Engine::W_WIDTH - 50, Engine::W_HALF_HEIGHT);
    //EndConst

    map<string, string> getSettings();
public:
    Game(int gameMode);

    map<string, string> g_Settings;

    void update(float elapsedTime);
};


#endif //MAD_PONG_GAME_H
