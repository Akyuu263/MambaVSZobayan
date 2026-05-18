#include "effect/healEffect.hpp"

#include "game.hpp"

#include "gameConfig.hpp"

HealEffect::HealEffect() : amount_(gConfig.healLives) {}

void HealEffect::Apply(Game &game) {
  game.stats_.SetLives(game.stats_.GetLives() + amount_);
}
