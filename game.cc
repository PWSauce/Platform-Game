#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <string>

Game::Game(std::string name, unsigned width, unsigned height)
    : window(sf::VideoMode{width, height}, name)
{
}

void Game::run()
{
    initialize();

    sf::Clock clock {}; 
    sf::Time timeSinceLastUpdate {sf::Time::Zero};
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            handleInput(event);
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > sf::seconds(1.0f / 60.0f))
        {
            timeSinceLastUpdate -= sf::seconds(1.0f / 60.0f);

            fixedUpdate();
        }

        render();
    }
}

void Game::initialize()
{

}

void Game::handleInput(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        window.close();
}

void Game::fixedUpdate()
{

}

void Game::render()
{
    window.clear();

    window.display();
}
