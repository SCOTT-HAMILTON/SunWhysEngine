#include <iostream>
#include "Behavior.h"

void Behavior::draw() {
    window.draw(m_sprite);
    m_sprite.setPosition(m_x, m_y);
}

