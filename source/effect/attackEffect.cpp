#include "effect/attackEffect.hpp"

#include "game.hpp"

AttackEffect::AttackEffect() {}

void AttackEffect::Apply(Game &game) {
  game.weapons_.emplace_back(game.paddle_, game.WeaponTexture_);
}
