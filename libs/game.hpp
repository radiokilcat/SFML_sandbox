#include "SFML/Graphics.hpp"
#include "gameobject.hpp"
#include <vector>

class Game
{
public:
    Game(sf::RenderWindow* window);
    void run();
    void render();

    std::vector<GameObject> game_objects() const;
    void add_game_object(GameObject game_objects);

private:
    sf::RenderWindow* window_;
    std::vector<GameObject> game_objects_;
};
