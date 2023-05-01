#include "player.h"
#include <iostream>

namespace
{
    double xDt {};
    float yDt {};
}

Player::Player()
{
}

Player::Player(sf::Texture const &tex)
    : sf::Sprite(tex)
{
    float width {getLocalBounds().width};
    float height {getLocalBounds().height};

    setOrigin(width / 2, height / 2);

    setPosition(100, 100);
}

void Player::input(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        xDt++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        xDt--;
    }
}

void Player::update()
{
    move(sf::Vector2f(xDt, 0.0));
}

void Player::shoot()
{
}
