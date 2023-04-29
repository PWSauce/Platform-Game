#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>

class Game
{
public:
    Game(std::string name, unsigned width, unsigned height);
    virtual ~Game() = default;

    void run();
protected:
    void initialize();
    void handleInput(sf::Event);
    void fixedUpdate();
    void render();

private:
    sf::RenderWindow window;
};

#endif // GAME_H