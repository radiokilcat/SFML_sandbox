#include "SFML/Graphics.hpp"
#include "game.hpp"
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    Game game(&window);

    GameObject obj1(1, 2, 30, 230, sf::Color::Red);
    GameObject obj2(5, 10, 10, 22, sf::Color::Green);
    GameObject obj3(34, 4, 3, 342, sf::Color::Blue);
    game.add_game_object(obj1);
    game.add_game_object(obj2);
    game.add_game_object(obj3);

    game.run();
    return 0;
}
