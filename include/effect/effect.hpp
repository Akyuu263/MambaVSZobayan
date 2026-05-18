#pragma once

#include <SFML/Graphics.hpp>

class Game;

class IEffect {
public:
  virtual ~IEffect() = default;
  virtual void Apply(Game &game) = 0;
};
