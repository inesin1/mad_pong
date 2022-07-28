//
// Ball
//

#include "Ball.h"

Ball::Ball() {
    bl_Position = Vector2f(Engine::W_HALF_WIDTH, Engine::W_HALF_HEIGHT);
}

Sprite Ball::getSprite() {
    return bl_Sprite;
}

void Ball::update(float elapsedTime) {
    bl_Sprite.setPosition(bl_Position);
}
