//
// Bat
//

//-----------------------
// AI Mode:
//     0 - Off
//     1 - On
//-----------------------

#ifndef MAD_PONG_BAT_H
#define MAD_PONG_BAT_H

#pragma once

//Include//
#include "GameObject.h"
//EndInclude//

using namespace sf;

class Bat : public GameObject{
private:
    Texture bt_Texture;
    Sprite bt_Sprite;

    Vector2f bt_Position;
    float bt_Speed{};

    bool bt_AI; //Искуственный интеллект

    void input(float elapsedTime);
public:
    Bat(Game &context);
    Bat(Game &context, Vector2f pos, bool isRight);

    //Sprite g
    Sprite getSprite();

    //Pos g/s
    void setPosition(Vector2f pos);
    float getPosY();
    void setPosY(float posY);

    //Speed g
    float getSpeed();

    void update(float elapsedTime);

    void setAI(bool activate);
};


#endif //MAD_PONG_BAT_H
