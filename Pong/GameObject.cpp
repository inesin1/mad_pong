//
// GameObject
//

#include "GameObject.h"

bool GameObject::isCollide(GameObject gameObj) {
    return o_CollisionBox.intersects(gameObj.o_CollisionBox);
}

GameObject::GameObject(Game &context) : o_Context(context) {}
