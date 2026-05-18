#include "game.hpp"

#include "ball.hpp"

#include "gameConfig.hpp"

#include "effect/attackEffect.hpp"
#include "effect/healEffect.hpp"
#include "effect/slowEffect.hpp"

#include "weapon.hpp"

#include <memory>

Game::Game()
    : window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), "Bounce") {
  window_.setVerticalSyncEnabled(true);
  Init();
}

bool Game::IsRunning() const { return window_.isOpen(); }

void Game::ProcessEvents() {
  while (std::optional<sf::Event> event = window_.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window_.close();
    }
  }
}

void Game::Update() {
  float deltaTime = clock_.restart().asSeconds();

  if (ballSpawnClock_.getElapsedTime().asSeconds() >
      gConfig.ballSpawnCooldown) {
    balls_.emplace_back(ballTexture_);
    ballSpawnClock_.restart();
  }

  if (itemSpawnClock_.getElapsedTime().asSeconds() >
      gConfig.itemSpawnCooldown) {
    items_.push_back(itemConstructor_.RandomConstruct());
    itemSpawnClock_.restart();
  }

  paddle_.Move(deltaTime);

  for (Ball &ball : balls_) {
    ball.Move(deltaTime);
  }

  for (Weapon &weapon : weapons_) {
    weapon.Move(deltaTime);
    weapon.Rotate(deltaTime);
  }

  HandleBallsCollisions();
  HandleItemsCollisions();
  HandleWeaponsCollisions();

  if (stats_.GetLives() <= 0) {
    Restart();
  }
}

void Game::Render() {
  window_.clear();

  background_.Draw(window_);

  paddle_.Draw(window_);

  for (const Item &item : items_) {
    item.Draw(window_);
  }

  for (const Ball &ball : balls_) {
    ball.Draw(window_);
  }

  for (const Weapon &weapon : weapons_) {
    weapon.Draw(window_);
  }

  stats_.Draw(window_);

  window_.display();
}

void Game::HandleBallsCollisions() {
  sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();

  for (Ball &ball : balls_) {
    sf::FloatRect ballBounds = ball.GetGlobalBounds();

    bool isColiding = ballBounds.findIntersection(paddleBounds).has_value();

    if (isColiding && ball.GetDirection().y > 0) {
      ball.Bounce();
      stats_.SetScore(stats_.GetScore() + 1);
      sounds_.PlayBounceSound();
    }
  }

  std::size_t ballsMissed =
      std::erase_if(balls_, [](const Ball &ball) { return ball.IsOutside(); });
  if (ballsMissed > 0) {
    stats_.SetLives(stats_.GetLives() - ballsMissed);
  }
}

void Game::HandleItemsCollisions() {
  for (auto it = items_.begin(); it != items_.end();) {
    bool collided = false;

    Item &item = *it;
    sf::FloatRect itemBounds = item.GetGlobalBounds();

    for (Ball &ball : balls_) {
      sf::FloatRect ballBounds = ball.GetGlobalBounds();

      bool isColiding = ballBounds.findIntersection(itemBounds).has_value();

      if (isColiding) {
        item.Use(*this);
        collided = true;
        break;
      }
    }

    if (collided) {
      it = items_.erase(it);
    } else {
      ++it;
    }
  }
}

void Game::HandleWeaponsCollisions() {
  for (auto it = balls_.begin(); it != balls_.end();) {
    bool collided = false;

    Ball &ball = *it;
    sf::FloatRect ballBounds = ball.GetGlobalBounds();

    for (Weapon &weapon : weapons_) {
      sf::FloatRect weaponBounds = weapon.GetGlobalBounds();

      bool isColiding = weaponBounds.findIntersection(ballBounds).has_value();

      if (isColiding) {
        collided = true;
        break;
      }
    }

    if (collided) {
      it = balls_.erase(it);
    } else {
      ++it;
    }
  }

  std::erase_if(weapons_,
                [](const Weapon &weapon) { return weapon.IsOutside(); });
}

void Game::Init() {
  itemConstructor_.AddItem("content/RedTea.png",
                           []() { return std::make_unique<HealEffect>(); });
  itemConstructor_.AddItem("content/Lolly.jpg",
                           []() { return std::make_unique<SlowEffect>(); });
  itemConstructor_.AddItem("content/Attack.png",
                           []() { return std::make_unique<AttackEffect>(); });

  bool load1 = ballTexture_.loadFromFile("content/Zobayan.jpg");
  bool load2 = WeaponTexture_.loadFromFile("content/Basketball.png");
}

void Game::Restart() {
  sounds_.PlayOutSound();
  balls_.clear();
  items_.clear();
  weapons_.clear();
  ballSpawnClock_.restart();
  itemSpawnClock_.restart();
  stats_.Reset();
}
