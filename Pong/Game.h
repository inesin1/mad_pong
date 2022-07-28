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

#include "Bat.h"
#include "Ball.h"
//EndInclude

//Using
using json = nlohmann::json;
using namespace std;
//EndUsing

class Game {
private:
    int g_Mode = 1;

    //Const
    const Vector2f G_DEFAULT_BAT_L_POS = Vector2f(50, W_HALF_HEIGHT);
    const Vector2f G_DEFAULT_BAT_R_POS = Vector2f(W_WIDTH - 50, W_HALF_HEIGHT);
    //EndConst

    map<string, string> getSettings();
public:
    Game();

    map<string, string> g_Settings;

    Bat g_BatL;
    Bat g_BatR;

    Ball g_Ball;

    void setMode(int gameMode);

    void start();

    void update(float elapsedTime);
    void input(float elapsedTime);
};


#endif //MAD_PONG_GAME_H
