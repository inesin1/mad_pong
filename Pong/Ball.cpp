//
// Ball
//

#include "Ball.h"

Ball::Ball() {
    bl_Speed = 400.0f;

    //texture n sprite
    bl_Texture.loadFromFile("assets/s_ball.png");
    bl_Sprite.setTexture(bl_Texture);

    bl_Position = Vector2f(W_HALF_WIDTH, W_HALF_HEIGHT);

    bl_Sprite.setOrigin(bl_Sprite.getLocalBounds().width / 2, bl_Sprite.getLocalBounds().height / 2);
}

Sprite Ball::getSprite() {
    return bl_Sprite;
}

void Ball::update(float elapsedTime) {
    bl_Sprite.setPosition(bl_Position);
}
