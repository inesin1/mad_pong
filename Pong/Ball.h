//
// Ball
//

#ifndef MAD_PONG_BALL_H
#define MAD_PONG_BALL_H

#include "SFML/Graphics.hpp"
#include "Engine.h"

using namespace sf;

class Ball {
private:
    Texture bl_Texture;
    Sprite bl_Sprite;

    Vector2f bl_Position;
    float bl_Speed;
public:
    Ball();

    Sprite getSprite();

    void update(float elapsedTime);
};


#endif //MAD_PONG_BALL_H
