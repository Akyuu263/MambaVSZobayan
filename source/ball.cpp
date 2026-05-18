#include "ball.hpp"

#include "random.hpp"

#include "gameConfig.hpp"

#include <numbers>

Ball::Ball(const sf::Texture &texture)
    : shape_(gConfig.ballRadius), speed_(gConfig.ballSpeed) {
  shape_.setFillColor(sf::Color::White);
  shape_.setTexture(&texture);
  shape_.setOrigin(shape_.getGeometricCenter());
  shape_.setPosition(
      {gConfig.windowSize.x * 0.50f, gConfig.windowSize.y * 0.25f});

  float angle = gRandom.GetFloat(0, 2 * std::numbers::pi_v<float>);
  direction_ = {std::cos(angle), std::sin(angle)};
}

void Ball::Draw(sf::RenderWindow &window) const { window.draw(shape_); }

void Ball::Move(float deltaTime) {
  sf::Vector2f lastPosition = shape_.getPosition();

  shape_.move(direction_ * speed_ * deltaTime);

  if (shape_.getPosition().x < shape_.getRadius() ||
      shape_.getPosition().x >= gConfig.windowSize.x - shape_.getRadius()) {
    shape_.setPosition(lastPosition);
    direction_.x *= -1;
  }

  if (shape_.getPosition().y < shape_.getRadius()) {
    shape_.setPosition(lastPosition);
    direction_.y *= -1;
  }
}

sf::FloatRect Ball::GetGlobalBounds() const { return shape_.getGlobalBounds(); }

sf::Vector2f Ball::GetDirection() const { return direction_; }

void Ball::Bounce() { direction_.y *= -1; }

float Ball::GetSpeed() { return speed_; }

void Ball::SetSpeed(float speed) { speed_ = speed; }

bool Ball::IsOutside() const {
  return shape_.getPosition().y - shape_.getRadius() > gConfig.windowSize.y;
}
