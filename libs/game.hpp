#include "SFML/Graphics.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include "fixed_queue.hpp"

#include <vector>
#include <map>

class Game
{
public:
    Game(sf::RenderWindow* window);
    void run();
    void render();

    void add_game_object(GameObject* game_objects);
    void set_player(Player* player);

    void track_object(GameObject* game_objects);

    void handleKey();
    bool intersects(GameObject* a, GameObject* b);


private:

    void handle_collision(GameObject* a, GameObject* b);
    bool detect_collision();

    sf::RenderWindow* window_;
    std::vector<GameObject*> game_objects_;
    Player* player_;
    std::map<GameObject*, FixedQueue<sf::Vector2f, 10>> object_tracking_;
};
