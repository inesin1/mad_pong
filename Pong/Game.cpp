//
// Game
//

#include "Game.h"

map<string, string> Game::getSettings() {
    std::ifstream ifs("settings.json");

    json data = json::parse(ifs);

    map<string, string> settings = {
            {"control", data.value("control", "keyboard")},
            {"complexity", data.value("complexity", "medium")},
            {"sound", data.value("sound", "4")}
    };

    return settings;
}

Game::Game() = default;

void Game::update(float elapsedTime) {
    input(elapsedTime);

    g_BatR.update(elapsedTime);
    g_BatL.update(elapsedTime);

    g_Ball.update(elapsedTime);
}

void Game::input(float elapsedTime) {
    if (g_Mode == 0) {
        //VS AI
        if (g_Settings["control"] == "keyboard") {
            //Keyboard control
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                g_BatR.setPosY(g_BatR.getPosY() - g_BatR.getSpeed() * elapsedTime);

                //Чтоб не заходила за границы
                if (g_BatR.getPosY() <= 0 + g_BatR.o_CollisionBox.height / 2)
                    g_BatR.setPosY(g_BatR.getPosY() + g_BatR.getSpeed() * elapsedTime);
            }

            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                g_BatR.setPosY(g_BatR.getPosY() + g_BatR.getSpeed() * elapsedTime);

                if (g_BatR.getPosY() >= W_HEIGHT - g_BatR.o_CollisionBox.height / 2)
                    g_BatR.setPosY(g_BatR.getPosY() - g_BatR.getSpeed() * elapsedTime);
            }
        } else {
            //Mouse control

        }
    } else {
        //VS PLAYER

        //LEFT BAT
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            g_BatL.setPosY(g_BatL.getPosY() - g_BatL.getSpeed() * elapsedTime);

            if (g_BatL.getPosY() <= 0 + g_BatL.o_CollisionBox.height / 2)
                g_BatL.setPosY(g_BatL.getPosY() + g_BatL.getSpeed() * elapsedTime);
        }

        if (Keyboard::isKeyPressed(Keyboard::S)) {
            g_BatL.setPosY(g_BatL.getPosY() + g_BatL.getSpeed() * elapsedTime);

            if (g_BatL.getPosY() >= W_HEIGHT - g_BatL.o_CollisionBox.height / 2)
                g_BatL.setPosY(g_BatL.getPosY() - g_BatL.getSpeed() * elapsedTime);
        }
        //EndLeftBat

        //RIGHT BAT
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            g_BatR.setPosY(g_BatR.getPosY() - g_BatR.getSpeed() * elapsedTime);

            if (g_BatR.getPosY() <= 0 + g_BatR.o_CollisionBox.height / 2)
                g_BatR.setPosY(g_BatR.getPosY() + g_BatR.getSpeed() * elapsedTime);
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            g_BatR.setPosY(g_BatR.getPosY() + g_BatR.getSpeed() * elapsedTime);

            if (g_BatR.getPosY() >= W_HEIGHT - g_BatR.o_CollisionBox.height / 2)
                g_BatR.setPosY(g_BatR.getPosY() - g_BatR.getSpeed() * elapsedTime);
        }
        //EndRightBat
    }
}

void Game::setMode(int gameMode) {
    g_Mode = gameMode;
}

void Game::start() {
    g_Settings = getSettings();

    if (g_Mode == 0)
        g_BatL.setAI(true);
}


