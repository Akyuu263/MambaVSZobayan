#pragma once

#include "effect.hpp"

class SlowEffect : public IEffect {
private:
  float slowRate;

public:
  SlowEffect();

  void Apply(Game &game) override;
};
