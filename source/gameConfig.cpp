#include "gameConfig.hpp"
#include <SFML/System/Angle.hpp>

GameConfig::GameConfig()
    : windowSize(600, 800), paddleSize(120, 20), paddleSpeed(750),
      ballSpeed(250), weaponSpeed(750), ballRadius(10), itemRadius(25),
      weaponRadius(40), ballSpawnCooldown(2), musicVolume(25),
      bounceSoundVolume(15), outSoundVolume(15), itemSpawnCooldown(5),
      ballSlowRate(0.9), startingLives(5), healLives(1) {
  weaponRotateSpeed = sf::degrees(360);
}
