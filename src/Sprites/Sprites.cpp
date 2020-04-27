#include <iostream>
#include "Sprites.h"

void Sprites::draw() {
    window.draw(m_sprite);

    m_sprite.setPosition(x, y);


    hitbox = m_sprite.getGlobalBounds();
}

