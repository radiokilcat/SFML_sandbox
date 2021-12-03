#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    virtual void draw(sf::RenderTarget* target) = 0;
    void update(sf::Vector2u targetSize);
    sf::FloatRect getGlobalBounds();

protected:
    GameObject(float x, float y, sf::Shape* shape);
    sf::Vector2f position_;
    sf::Shape* shape_;
    sf::Vector2f velocity_;
    sf::Vector2f accel_;
};

