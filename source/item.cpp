#include "item.hpp"

#include "random.hpp"

#include "gameConfig.hpp"

Item::Item(const sf::Texture &texture, std::unique_ptr<IEffect> effect)
    : shape_(gConfig.itemRadius), effect_(std::move(effect)) {
  shape_.setFillColor(sf::Color::White);
  shape_.setOrigin(shape_.getGeometricCenter());
  shape_.setOutlineThickness(2.0f);
  shape_.setOutlineColor(sf::Color::Black);

  float posx =
      gRandom.GetFloat(0 + shape_.getRadius(),
                       gConfig.windowSize.x * 1.00f - shape_.getRadius());
  float posy =
      gRandom.GetFloat(0 + shape_.getRadius(),
                       gConfig.windowSize.y * 0.80f - shape_.getRadius());
  shape_.setPosition({posx, posy});

  shape_.setTexture(&texture);
}

void Item::Draw(sf::RenderWindow &window) const { window.draw(shape_); }

void Item::Use(Game &game) {
  if (effect_)
    effect_->Apply(game);
}

sf::FloatRect Item::GetGlobalBounds() const { return shape_.getGlobalBounds(); }
