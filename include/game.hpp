#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "background.hpp"
#include "ball.hpp"
#include "gameSounds.hpp"
#include "gameStats.hpp"
#include "itemConstructor.hpp"
#include "paddle.hpp"
#include "weapon.hpp"

class HealEffect;
class SlowEffect;
class AttackEffect;

class Game {
private:
  sf::RenderWindow window_;
  sf::Clock clock_;

  Paddle paddle_;
  std::vector<Ball> balls_;
  sf::Clock ballSpawnClock_;

  sf::Clock itemSpawnClock_;

  GameStats stats_;
  GameSounds sounds_;
  Background background_;

  std::vector<Item> items_;
  ItemConstructor itemConstructor_;

  std::vector<Weapon> weapons_;

  sf::Texture ballTexture_;
  sf::Texture WeaponTexture_;

  friend class HealEffect;
  friend class SlowEffect;
  friend class AttackEffect;

public:
  Game();

  bool IsRunning() const;

  void ProcessEvents();
  void Update();
  void Render();

private:
  void HandleBallsCollisions();
  void HandleItemsCollisions();
  void HandleWeaponsCollisions();
  void Restart();
  void Init();
};
