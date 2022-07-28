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
#include <SFML/Graphics.hpp>
//EndInclude//

using namespace sf;

class Bat {
private:
    Texture bt_Texture;
    Sprite bt_Sprite;

    Vector2f bt_Position;
    float bt_Speed{};

    bool bt_AI{}; //Искуственный интеллект

    void input(float elapsedTime);
public:
    Bat();
    Bat(Vector2f pos);

    //Sprite g
    Sprite getSprite();

    //Pos g/s
    float getPosY();
    void setPosY(float posY);

    //Speed g
    float getSpeed();

    void update(float elapsedTime);

    void setAI(bool activate);
};


#endif //MAD_PONG_BAT_H
