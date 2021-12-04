#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    virtual void draw(sf::RenderTarget* target) = 0;
    void update(sf::Vector2u targetSize);
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getVelocity();

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    void move(sf::Vector2f velocity);
    void stop();

protected:
    GameObject(float x, float y, sf::Shape* shape);
    sf::Vector2f position_;
    sf::Shape* shape_;
    sf::Vector2f velocity_;
    sf::Vector2f accel_;
};

