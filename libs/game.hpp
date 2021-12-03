#include "SFML/Graphics.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include <vector>

class Game
{
public:
    Game(sf::RenderWindow* window);
    void run();
    void render();

    void add_game_object(GameObject* game_objects);
    void add_player(Player* player);
    void handleKey();
    bool intersects(GameObject* a, GameObject* b);

private:

    void handle_collision(GameObject* a, GameObject* b);
    sf::RenderWindow* window_;
    std::vector<GameObject*> game_objects_;
    Player* player_;
};
