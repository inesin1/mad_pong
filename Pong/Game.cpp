//
// Game
//

#include "Game.h"

map<string, string> Game::getSettings() {
    ifstream f("settings.json");
    json data = json::parse(f);

    map<string, string> settings = {
            {"control", data.value("control", "keyboard")},
            {"complexity", data.value("complexity", "medium")},
            {"sound", data.value("sound", "4")}
    };

    return settings;
}

Game::Game(int gameMode) {
    g_Settings = getSettings();

    Bat g_BatL(G_DEFAULT_BAT_L_POS);
    Bat g_BatR(G_DEFAULT_BAT_R_POS);

    Ball g_Ball;

    if (gameMode == 0)
        g_BatL.setAI(true);
}

void Game::update(float elapsedTime) {

}


