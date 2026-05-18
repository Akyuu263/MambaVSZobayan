#include "effect/slowEffect.hpp"

#include "game.hpp"

#include "gameConfig.hpp"

SlowEffect::SlowEffect() : slowRate(gConfig.ballSlowRate) {}

void SlowEffect::Apply(Game &game) {
  for (Ball &ball : game.balls_) {
    ball.SetSpeed(ball.GetSpeed() * slowRate);
  }
}
