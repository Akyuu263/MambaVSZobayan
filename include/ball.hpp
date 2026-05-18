#pragma once

#include <SFML/Graphics.hpp>

class Ball {
private:
  sf::CircleShape shape_;
  sf::Vector2f direction_;
  float speed_;

public:
  Ball(const sf::Texture &texture);

  void Draw(sf::RenderWindow &window) const;
  void Move(float deltaTime);
  void Bounce();
  void SetSpeed(float speed);
  float GetSpeed();

  sf::FloatRect GetGlobalBounds() const;
  sf::Vector2f GetDirection() const;
  bool IsOutside() const;
};
