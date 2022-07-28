//
// Game engine
//

#ifndef MAD_PONG_ENGINE_H
#define MAD_PONG_ENGINE_H

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine {
private:
    //Game window
    RenderWindow e_Window;
    void handleWindowEvents();

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
