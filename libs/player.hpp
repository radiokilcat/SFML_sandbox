#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"

class Player : public GameObject
{
public:
    Player(float x, float y, sf::Color color);
    void draw(sf::RenderTarget* target);
    void update(sf::Vector2u targetSize);

private:
    sf::CircleShape shape_;
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    sf::Vector2f accel_;
};
