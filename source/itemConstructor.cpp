#include "itemConstructor.hpp"

#include "random.hpp"

ItemConstructor::ItemConstructor() {}

void ItemConstructor::AddItem(
    const std::filesystem::path &texturePath,
    std::function<std::unique_ptr<IEffect>()> factory) {
  factories.push_back(factory);
  sf::Texture texture;
  bool load = texture.loadFromFile(texturePath); // 懒得写判断了
  textures.push_back(std::move(texture));
}

Item ItemConstructor::RandomConstruct() {
  int id = gRandom.GetInt(0, factories.size() - 1);
  return Item(textures[id], factories[id]());
}
