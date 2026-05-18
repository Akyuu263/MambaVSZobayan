#include "gameSounds.hpp"

#include "gameConfig.hpp"

GameSounds::GameSounds()
    : music_("content/SeeYouAgain.mp3"), bounceSoundBuffer_("content/Man.mp3"),
      bounceSound_(bounceSoundBuffer_), outSoundBuffer_("content/MambaOut.mp3"),
      outSound_(outSoundBuffer_) {
  music_.setVolume(gConfig.musicVolume);
  music_.setLooping(true);
  music_.play();

  bounceSound_.setVolume(gConfig.bounceSoundVolume);
  outSound_.setVolume(gConfig.outSoundVolume);
}

void GameSounds::PlayBounceSound() { bounceSound_.play(); }

void GameSounds::PlayOutSound() { outSound_.play(); }
