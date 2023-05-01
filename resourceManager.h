#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager() = default;

    void loadTexture(std::string const& name);
    sf::Texture& getTexture(std::string const& name);
private:
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};

#endif // RESOURCE_MANAGER_H