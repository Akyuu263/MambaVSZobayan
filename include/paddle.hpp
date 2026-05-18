#pragma once

#include <SFML/Graphics.hpp>

class Paddle {
private:
  sf::RectangleShape shape_;
  sf::Texture texture_;
  float speed_;

public:
  Paddle();

  void Draw(sf::RenderWindow &window) const;
  void Move(float deltaTime);

  sf::FloatRect GetGlobalBounds() const;
  sf::Vector2f GetPosition() const;
};
