#ifndef SUNWHYSENGINE_SPRITES_H
#define SUNWHYSENGINE_SPRITES_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class Sprites {
public:
  Sprites(sf::RenderWindow& window, std::string textureName, float x, float y): window(window) {
    if (!m_texture.loadFromFile("./assets/" + textureName))
        std::cout << textureName << " not found" << std::endl;

    m_sprite.setTexture(m_texture);
    this->x = x;
    this->y = y;
  }

  void draw();

  float x, y;
  sf::FloatRect hitbox;
private:
  sf::Texture m_texture;
  sf::Sprite m_sprite;
  sf::RenderWindow& window;
};


#endif //SUNWHYSENGINE_SPRITES_H
