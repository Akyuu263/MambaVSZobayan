#include "background.hpp"

Background::Background() : texture_("content/Mamba.jpg"), sprite_(texture_) {}

void Background::Draw(sf::RenderWindow &window) const { window.draw(sprite_); }
