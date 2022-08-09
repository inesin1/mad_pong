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

    int g_PlayerLScore = 0;
    int g_PlayerRScore = 0;
public:
    Game();

    map<string, string> g_Settings;
    Font g_DefaultFont;

    //GameObjects
    Bat g_BatL = Bat(*this, G_DEFAULT_BAT_L_POS, false);
    Bat g_BatR = Bat(*this, G_DEFAULT_BAT_R_POS, true);

    Ball g_Ball = Ball(*this);
    //End

    //Scores
    void addScorePlayerL();
    void addScorePlayerR();
    Text g_ScoreTable;
    void setScoreTable();
    //End

    void setMode(int gameMode);

    void start();
    void restart();

    void update(float elapsedTime);
    void input(float elapsedTime);
};


#endif //MAD_PONG_GAME_H
