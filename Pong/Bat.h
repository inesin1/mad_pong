//
// Bat
//

#ifndef MAD_PONG_BAT_H
#define MAD_PONG_BAT_H

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat {
private:
    Texture b_Texture;
    Sprite b_Sprite;

    Vector2f b_Position;
    float b_Speed;

    void input(float elapsedTime);
public:
    Bat(float posX, float posY);

    Sprite getSprite();

    void update(float elapsedTime);
};


#endif //MAD_PONG_BAT_H
