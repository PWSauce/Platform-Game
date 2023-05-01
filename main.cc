#include "game.h"
#include "player.h"

int main()
{
    Game game{"demo", 800, 600};
    Player player{};

    game.run();

    return 0;
}