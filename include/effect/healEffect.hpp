#pragma once

#include "effect.hpp"

class HealEffect : public IEffect {
private:
  int amount_;

public:
  HealEffect();

  void Apply(Game &game) override;
};
