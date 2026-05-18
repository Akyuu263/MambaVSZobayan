#include "paddle.hpp"

#include "gameConfig.hpp"

#include <algorithm>

Paddle::Paddle() : shape_(gConfig.paddleSize), speed_(gConfig.paddleSpeed) {
  bool load = texture_.loadFromFile("content/Elbow.jpg"); // 懒得写判断了
  shape_.setFillColor(sf::Color::White);
  shape_.setTexture(&texture_);
  shape_.setOutlineThickness(2.f);
  shape_.setOutlineColor(sf::Color::Black);
  shape_.setOrigin(shape_.getGeometricCenter());
  shape_.setPosition(
      {gConfig.windowSize.x * 0.50f, gConfig.windowSize.y * 0.85f});
}

void Paddle::Draw(sf::RenderWindow &window) const { window.draw(shape_); }

void Paddle::Move(float deltaTime) {

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    shape_.move(sf::Vector2f(speed_ * deltaTime, 0));
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    shape_.move(sf::Vector2f(-speed_ * deltaTime, 0));
  }

  float halfwidth = shape_.getSize().x / 2;
  float x = std::clamp(shape_.getPosition().x, halfwidth,
                       gConfig.windowSize.x - halfwidth);
  shape_.setPosition({x, shape_.getPosition().y});
}

sf::FloatRect Paddle::GetGlobalBounds() const {
  return shape_.getGlobalBounds();
}

sf::Vector2f Paddle::GetPosition() const { return shape_.getPosition(); }
