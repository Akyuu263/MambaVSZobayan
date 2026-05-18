#include "weapon.hpp"

#include "gameConfig.hpp"

Weapon::Weapon(const Paddle &paddle, const sf::Texture &texture)
    : shape_(gConfig.weaponRadius), speed_(gConfig.weaponSpeed),
      rotateSpeed_(gConfig.weaponRotateSpeed) {
  shape_.setFillColor(sf::Color::White);
  shape_.setTexture(&texture);
  shape_.setOrigin(shape_.getGeometricCenter());
  shape_.setPosition(paddle.GetPosition() +
                     sf::Vector2f{0, -gConfig.weaponRadius});
}

void Weapon::Draw(sf::RenderWindow &window) const { window.draw(shape_); }

void Weapon::Move(float deltaTime) {
  shape_.move(sf::Vector2f(0, -speed_ * deltaTime));
}

void Weapon::Rotate(float deltaTime) {
  shape_.rotate(rotateSpeed_ * deltaTime);
}

sf::FloatRect Weapon::GetGlobalBounds() const {
  return shape_.getGlobalBounds();
}

bool Weapon::IsOutside() const {
  return shape_.getPosition().y + shape_.getRadius() < 0;
}
