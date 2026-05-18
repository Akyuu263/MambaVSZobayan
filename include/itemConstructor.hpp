#pragma once

#include "item.hpp"

#include <filesystem>
#include <functional>
#include <vector>

class ItemConstructor {
private:
  std::vector<std::function<std::unique_ptr<IEffect>()>> factories;
  std::vector<sf::Texture> textures;

public:
  ItemConstructor();

  void AddItem(const std::filesystem::path &texturePath,
               std::function<std::unique_ptr<IEffect>()> factory);

  Item RandomConstruct();
};
