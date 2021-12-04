#include "SFML/Graphics.hpp"
#include "game.hpp"
#include "player.hpp"
#include "npc.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    Game game(&window);

    Player* obj1 = new Player(1, 2, sf::Color::Red);
    Npc* obj2 = new Npc(100, 10, sf::Color::Green);
    Npc* obj3 = new Npc(200, 50, sf::Color::Blue);
    game.add_game_object(obj1);
    game.set_player(obj1);
    game.add_game_object(obj2);
    game.add_game_object(obj3);

    game.run();
    return 0;
}
