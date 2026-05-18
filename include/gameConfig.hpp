#pragma once

#include <SFML/Graphics.hpp>

struct GameConfig {
  sf::Vector2f windowSize;
  sf::Vector2f paddleSize;
  float paddleSpeed;
  float ballRadius;
  float itemRadius;
  float weaponRadius;
  float ballSpeed;
  float weaponSpeed;
  float ballSpawnCooldown;
  float musicVolume;
  float bounceSoundVolume;
  float outSoundVolume;
  float itemSpawnCooldown;
  float ballSlowRate;
  int startingLives;
  int healLives;
  sf::Angle weaponRotateSpeed;

  GameConfig();
};

inline const GameConfig gConfig;
