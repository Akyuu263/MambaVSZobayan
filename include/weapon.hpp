#pragma once

#include "paddle.hpp"

#include <SFML/Graphics.hpp>

class Weapon {
private:
  sf::CircleShape shape_;
  float speed_;
  sf::Angle rotateSpeed_;

public:
  Weapon(const Paddle &paddle, const sf::Texture &texture);

  void Draw(sf::RenderWindow &window) const;
  void Move(float deltaTime);
  void Rotate(float deltaTime);

  sf::FloatRect GetGlobalBounds() const;
  bool IsOutside() const;
};
