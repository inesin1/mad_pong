//
// Ball
//

#ifndef MAD_PONG_BALL_H
#define MAD_PONG_BALL_H

#include "SFML/Graphics.hpp"
#include "Gamedef.h"
#include "GameObject.h"

using namespace sf;

class Ball : public GameObject{
private:
    Texture bl_Texture;
    Sprite bl_Sprite;

    Vector2f bl_Position;

    float bl_Speed;
    float bl_Direction;         //in degrees

    bool canCollide = true;     //Может ли вступать в коллизию с объектами

    bool bl_IsSleep = false;
    int bl_SleepTime = 1000.0f;  //in ms
public:
    Ball(Game &context);

    Sprite getSprite();
    void setPosition(Vector2f pos);
    void changeDir();
    void sleep();

    void move(float elapsedTime);
    void update(float elapsedTime);

    void checkCollision();
};


#endif //MAD_PONG_BALL_H
