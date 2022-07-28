//
// Bat
//

//INCLUDE//
#include "Bat.h"
#include "Game.h"
//EndInclude//

Bat::Bat(float posX, float posY) {
    b_Speed = 400.0f;

    //texture n sprite
    b_Texture.loadFromFile("assets/s_bat.png");
    b_Sprite.setTexture(b_Texture);

    //start pos
    b_Position.x = posX;
    b_Position.y = posY;
}

Sprite Bat::getSprite() {
    return b_Sprite;
}

void Bat::update(float elapsedTime) {
    b_Sprite.setPosition(b_Position);
}

void Bat::input(float elapsedTime) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        b_Position.y += b_Speed * elapsedTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        b_Position.y -= b_Speed * elapsedTime;
    }
}
