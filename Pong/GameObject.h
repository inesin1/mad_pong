//
// GameObject
//

#ifndef MAD_PONG_GAMEOBJECT_H
#define MAD_PONG_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
class Game;

using namespace sf;

class GameObject {
public:
    GameObject(Game& context);
    Game& o_Context;

    FloatRect o_CollisionBox;

    bool isCollide(GameObject gameObj);
};


#endif //MAD_PONG_GAMEOBJECT_H
