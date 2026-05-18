#pragma once

#include "effect/effect.hpp"

#include <SFML/Graphics/Rect.hpp>

#include <memory>

class Item {
private:
  sf::CircleShape shape_;
  sf::Texture texture_;

  std::unique_ptr<IEffect> effect_;

public:
  Item(const sf::Texture &texture, std::unique_ptr<IEffect> effect);

  void Draw(sf::RenderWindow &window) const;

  void Use(Game &game);

  sf::FloatRect GetGlobalBounds() const;
};
