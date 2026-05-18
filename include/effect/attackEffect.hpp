#pragma once

#include "effect.hpp"

class AttackEffect : public IEffect {
public:
  AttackEffect();

  void Apply(Game &game) override;
};
