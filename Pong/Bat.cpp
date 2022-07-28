//
// Bat
//

//INCLUDE//
#include "Bat.h"
#include "Game.h"
//EndInclude//

Bat::Bat(Vector2f pos) {
    bt_Speed = 400.0f;

    //texture n sprite
    bt_Texture.loadFromFile("assets/s_bat.png");
    bt_Sprite.setTexture(bt_Texture);

    //start pos
    bt_Position = pos;
}

Sprite Bat::getSprite() {
    return bt_Sprite;
}

void Bat::update(float elapsedTime) {
    bt_Sprite.setPosition(bt_Position);
}

void Bat::input(float elapsedTime) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        bt_Position.y += bt_Speed * elapsedTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        bt_Position.y -= bt_Speed * elapsedTime;
    }
}

void Bat::setAI(bool activate) {
    bt_AI = activate;
}
