#include <SFML/Graphics.hpp>

class GameObject
{
public:
    GameObject(float x, float y, sf::Color color);
    void move(float dx, float dy);
    void draw(sf::RenderTarget* target);
    void update(sf::Vector2u targetSize);

    sf::CircleShape shape() const;

private:
    sf::CircleShape shape_;
    sf::Vector2f position_;
    sf::Vector2f velocity_ = {0.001f, 0.001f};
    sf::Vector2f accel_ = {0.0001f, 0.0001f};
};

