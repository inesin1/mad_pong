//
// Bat
//

//INCLUDE//
#include "Bat.h"
#include "Game.h"
//EndInclude//

Bat::Bat(Game &context, Vector2f pos, bool isRight) : GameObject(context){
    bt_Speed = 400.0f;

    //texture n sprite
    if (isRight)
        bt_Texture.loadFromFile("assets/s_bat_right.png");
    else
        bt_Texture.loadFromFile("assets/s_bat_left.png");
    bt_Sprite.setTexture(bt_Texture);

    //start pos
    bt_Position = pos;

    bt_Sprite.setOrigin(bt_Sprite.getLocalBounds().width / 2, bt_Sprite.getLocalBounds().height / 2);
}

Sprite Bat::getSprite() {
    return bt_Sprite;
}

void Bat::update(float elapsedTime) {
    bt_Sprite.setPosition(bt_Position);
    o_CollisionBox = bt_Sprite.getGlobalBounds();
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

float Bat::getPosY() {
    return bt_Position.y;
}

void Bat::setPosY(float posY) {
    bt_Position.y = posY;
}

float Bat::getSpeed() {
    return bt_Speed;
}

Bat::Bat(Game &context) : GameObject(context){}

void Bat::setPosition(Vector2f pos) {
    bt_Position = pos;
}
