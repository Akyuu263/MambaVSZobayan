#include "gameStats.hpp"

#include "gameConfig.hpp"

#include <fstream>

#include <string>

GameStats::GameStats()
    : font_("content/Montserrat-Medium.ttf"), scoreText_(font_),
      livesText_(font_), highScoreText_(font_) {
  scoreText_.setPosition({10, 10});
  scoreText_.setFillColor(sf::Color::Cyan);
  SetScore(0);

  livesText_.setPosition({10, 60});
  livesText_.setFillColor(sf::Color::Red);
  SetLives(gConfig.startingLives);

  highScoreText_.setPosition({10, 110});
  highScoreText_.setFillColor(sf::Color::Green);

  if (std::ifstream file{"HighScores.txt"}) {
    file >> highScore_;
  } else {
    highScore_ = 0;
  }

  SetHighScore(highScore_);
}

void GameStats::Draw(sf::RenderWindow &window) const {
  window.draw(scoreText_);
  window.draw(livesText_);
  window.draw(highScoreText_);
}

void GameStats::SetScore(int score) {
  score_ = score;
  scoreText_.setString("Score: " + std::to_string(score_));
}

void GameStats::SetLives(int lives) {
  lives_ = lives;
  livesText_.setString("Lives: " + std::to_string(lives_));
}

void GameStats::SetHighScore(int highScore) {
  highScore_ = highScore;
  highScoreText_.setString("High: " + std::to_string(highScore_));
}

int GameStats::GetScore() const { return score_; }

int GameStats::GetLives() const { return lives_; }

int GameStats::GetHighScore() const { return highScore_; }

void GameStats::Reset() {
  if (score_ > highScore_) {
    if (std::ofstream file{"HighScores.txt"}) {
      file << score_;
    }

    SetHighScore(score_);
  }

  SetScore(0);
  SetLives(gConfig.startingLives);
}
