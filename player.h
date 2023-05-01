#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
    Player();
    Player(sf::Texture const& tex);

    void input(sf::Event event);
    void update();
private:
    void playerMove(int xDt, int yDt);
    void shoot();
};

#endif // PLAYER_H