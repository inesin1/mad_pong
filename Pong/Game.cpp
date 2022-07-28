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
