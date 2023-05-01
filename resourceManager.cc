#include "resourceManager.h"
#include <iostream>
#include <sstream>

ResourceManager::ResourceManager()
    : textures()
{
}

void ResourceManager::loadTexture(std::string const &name)
{
    sf::Texture texture;
    if (texture.loadFromFile(name))
    {
        std::cout << name << std::endl;
        textures.emplace(std::make_pair(name, std::make_unique<sf::Texture>(texture)));
    }
}

sf::Texture& ResourceManager::getTexture(std::string const& name)
{
    return *textures.find(name)->second;
}
