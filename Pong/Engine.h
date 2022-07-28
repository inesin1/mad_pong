//
// Game engine
//

#ifndef MAD_PONG_ENGINE_H
#define MAD_PONG_ENGINE_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

class Engine {
private:
    //Game window
    RenderWindow e_Window;
    void handleWindowEvents();

    Game e_Game;

    //Initialize game objects
    void init();

    //update game objects
    void update(float dtAsSeconds);

    //draw game objects
    void draw();

public:
    Engine();

    void start();
};


#endif //MAD_PONG_ENGINE_H
