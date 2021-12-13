#include "SFML/Graphics.hpp"
#include "game.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "boxcollider.hpp"
#include <iostream>

static const unsigned short SCREEN_WIDTH = 800;
static const unsigned short SCREEN_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "My window");
    window.setFramerateLimit(60);
    Game game(&window);

    Player* obj1 = new Player(30, 23, sf::Color::Red);
    Npc* obj2 = new Npc(100, 10, sf::Color::Green);
    Npc* obj3 = new Npc(200, 50, sf::Color::Blue);
    BoxCollider* obj4 = new BoxCollider(0, 0, SCREEN_WIDTH, 20, sf::Color::Yellow);
    BoxCollider* obj5 = new BoxCollider(0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, 20, sf::Color::Yellow);
    BoxCollider* obj6 = new BoxCollider(0, 0, 20, SCREEN_HEIGHT, sf::Color::Yellow);
    BoxCollider* obj7 = new BoxCollider(SCREEN_WIDTH - 20, 0, 20, SCREEN_HEIGHT, sf::Color::Yellow);
    game.add_game_object(obj1);
    game.set_player(obj1);
    game.add_game_object(obj2);
    game.add_game_object(obj3);
    game.add_game_object(obj4);
    game.add_game_object(obj5);
    game.add_game_object(obj6);
    game.add_game_object(obj7);

    game.run();
    return 0;
}
