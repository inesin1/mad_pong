//
// Game
//

#include <iostream>
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

    setScoreTable();
}

void Game::input(float elapsedTime) {
    //Game input
    if (Keyboard::isKeyPressed(Keyboard::R)) {
        restart();
    }

    //Bat input
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
    if (!g_DefaultFont.loadFromFile("assets/AtariClassicSmooth.ttf")) {
        printf("Load font error!"); std::cout << endl;
    }

    if (g_Mode == 0)
        g_BatL.setAI(true);
}

void Game::restart() {
    g_Ball.setPosition(G_DEFAULT_BALL_POS);
    g_Ball.changeDir();
    g_Ball.sleep();

    g_BatL.setPosition(G_DEFAULT_BAT_L_POS);
    g_BatR.setPosition(G_DEFAULT_BAT_R_POS);
}

void Game::setScoreTable() {
    g_ScoreTable.setFont(g_DefaultFont);
    g_ScoreTable.setString(to_string(g_PlayerLScore) + "\t" + to_string(g_PlayerRScore));
    g_ScoreTable.setCharacterSize(24);
    g_ScoreTable.setFillColor(Color::White);
    g_ScoreTable.setPosition(W_WIDTH / 2 - g_ScoreTable.getGlobalBounds().width / 2, 0);
}

void Game::addScorePlayerL() {
    g_PlayerLScore++;
}

void Game::addScorePlayerR() {
    g_PlayerRScore++;
}