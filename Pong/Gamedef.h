//
// Def global variables
//
#include "SFML/Graphics.hpp"
using namespace sf;
//

#ifndef MAD_PONG_GAMEDEF_H
#define MAD_PONG_GAMEDEF_H

#define W_WIDTH 800
#define W_HEIGHT 600
#define W_HALF_WIDTH (W_WIDTH / 2)
#define W_HALF_HEIGHT (W_HEIGHT / 2)

static const Vector2f G_DEFAULT_BAT_L_POS = Vector2f(50, W_HALF_HEIGHT);
static const Vector2f G_DEFAULT_BAT_R_POS = Vector2f(W_WIDTH - 50, W_HALF_HEIGHT);

#endif //MAD_PONG_GAMEDEF_H
