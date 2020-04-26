#ifndef SUNWHYSENGINE_BEHAVIORS_H
#define SUNWHYSENGINE_BEHAVIORS_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class Behavior {
public:
    Behavior(sf::RenderWindow& window, std::string textureName, float x, float y): window(window) {
        if (!m_texture.loadFromFile("./assets/" + textureName))
            std::cout << textureName << " not found" << std::endl;

        m_sprite.setTexture(m_texture);

        m_x = x;
        m_y = y;
    }

    void draw();

    float m_x, m_y;
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::RenderWindow& window;

};


#endif //SUNWHYSENGINE_BEHAVIORS_H
