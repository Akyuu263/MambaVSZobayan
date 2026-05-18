#pragma once

#include <SFML/Audio.hpp>

class GameSounds {
private:
  sf::Music music_;

  sf::SoundBuffer bounceSoundBuffer_;
  sf::Sound bounceSound_;

  sf::SoundBuffer outSoundBuffer_;
  sf::Sound outSound_;

public:
  GameSounds();

  void PlayBounceSound();
  void PlayOutSound();
};
