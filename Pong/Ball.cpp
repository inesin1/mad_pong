//
// Ball
//

#include "Ball.h"
#include "Game.h"
#include <cstdio>
#include <cmath>
#include <iostream>

Clock clockCollision;
Clock clockSleep;

Sprite Ball::getSprite() {
    return bl_Sprite;
}

void Ball::update(float elapsedTime) {
    if (clockCollision.getElapsedTime().asSeconds() >= 0.1f) {
        canCollide = true;
        clockCollision.restart();
    }

    if (clockSleep.getElapsedTime().asMilliseconds() >= bl_SleepTime){
        bl_IsSleep = false;
    }

    if (!bl_IsSleep)
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
    // Bats
    if (isCollide(o_Context.g_BatL) || isCollide(o_Context.g_BatR)){
        bl_Direction = 180 - bl_Direction;
        canCollide = false;
    }

    // Top & bottom screen
    if (bl_Position.y <= 0 || bl_Position.y >= W_HEIGHT) {
        bl_Direction = 360 - bl_Direction;
        canCollide = false;
    }

    // Right bat win
    if (bl_Position.x <= 0) {
        o_Context.addScorePlayerR();
        o_Context.restart();
    }

    // Left bat win
    if (bl_Position.x >= W_WIDTH) {
        o_Context.addScorePlayerL();
        o_Context.restart();
    }
}

Ball::Ball(Game &context) : GameObject(context) {
    bl_Speed = 400.0f;

    changeDir();

    //texture n sprite
    bl_Texture.loadFromFile("assets/s_ball.png");
    bl_Sprite.setTexture(bl_Texture);

    bl_Position = G_DEFAULT_BALL_POS;

    bl_Sprite.setOrigin(bl_Sprite.getLocalBounds().width / 2, bl_Sprite.getLocalBounds().height / 2);

    sleep();
}

void Ball::setPosition(Vector2f pos) {
    bl_Position = pos;
}

void Ball::changeDir() {
    std::srand(time(nullptr));

    if (std::rand() % 2 == 0)
        bl_Direction = 45;
    else
        bl_Direction = 135;
}

void Ball::sleep() {
    bl_IsSleep = true;
    clockSleep.restart();
}
