#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <string>

Game::Game(std::string name, unsigned width, unsigned height)
    : window(sf::VideoMode{width, height}, name), 
    resources(),
    player(),  
    running(true)
{
}

void Game::run()
{
    initialize();

    sf::Clock clock {}; 
    sf::Time timeSinceLastUpdate {sf::Time::Zero};
    while(running)
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
    resources.loadTexture("Textures/player.png");
    player = Player(resources.getTexture("Textures/player.png"));
}

void Game::handleInput(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        running = false;

    player.input(event);
}

void Game::fixedUpdate()
{
    player.update();
}

void Game::render()
{
    window.clear();
    window.draw(player);
    window.display();
}
