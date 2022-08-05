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

//INCLUDE//
#include "include/nlohmann/json.hpp"
#include <map>
#include <fstream>
#include "Gamedef.h"

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

    map<string, string> getSettings();
public:
    Game();

    map<string, string> g_Settings;

    Bat g_BatL = Bat(*this, G_DEFAULT_BAT_L_POS);
    Bat g_BatR = Bat(*this, G_DEFAULT_BAT_R_POS);

    Ball g_Ball = Ball(*this);

    void setMode(int gameMode);

    void start();

    void update(float elapsedTime);
    void input(float elapsedTime);
};


#endif //MAD_PONG_GAME_H
