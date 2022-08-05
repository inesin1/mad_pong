//
// Ball
//

#include "Ball.h"
#include "Game.h"
#include <cstdio>
#include <cmath>
#include <iostream>

Clock clock1;

Sprite Ball::getSprite() {
    return bl_Sprite;
}

void Ball::update(float elapsedTime) {
    if (clock1.getElapsedTime().asSeconds() >= 0.1f) {
        canCollide = true;
        clock1.restart();
    }

    move(elapsedTime);

    o_CollisionBox = bl_Sprite.getGlobalBounds();
    if (canCollide)
        checkCollision();

    bl_Sprite.setPosition(bl_Position);
}

float degToRad(float deg) {
    return deg * (M_PI / 180);
}

void Ball::move(float elapsedTime) {
    bl_Position.x += cos(degToRad(bl_Direction)) * bl_Speed * elapsedTime;
    bl_Position.y += sin(degToRad(bl_Direction)) * bl_Speed * elapsedTime;
}

void Ball::checkCollision() {
    if (isCollide(o_Context.g_BatL) || isCollide(o_Context.g_BatR)){
        bl_Direction = 180 - bl_Direction;
        canCollide = false;
    }

    if (bl_Position.y <= 0 || bl_Position.y >= W_HEIGHT) {
        bl_Direction = 360 - bl_Direction;
        canCollide = false;
    }
}

Ball::Ball(Game &context) : GameObject(context) {
    bl_Speed = 400.0f;

    std::srand(time(nullptr));

    if (std::rand() % 2 == 0)
        bl_Direction = 45;
    else
        bl_Direction = 135;

    //texture n sprite
    bl_Texture.loadFromFile("assets/s_ball_2.png");
    bl_Sprite.setTexture(bl_Texture);

    bl_Position = Vector2f(W_HALF_WIDTH, W_HALF_HEIGHT);

    bl_Sprite.setOrigin(bl_Sprite.getLocalBounds().width / 2, bl_Sprite.getLocalBounds().height / 2);
}
