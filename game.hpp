#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

class GameObject
{
public:
    GameObject(float x, float y, float xVelocity, float yVelocity, sf::Color color);
    float x() const;
    void setX(float x);

    float y() const;
    void setY(float y);

    float xVelocity() const;
    void setXVelocity(float xVelocity);

    float yVelocity() const;
    void setYVelocity(float yVelocity);

    void move();

    sf::CircleShape shape_;

private:
    float x_;
    float y_;
    float xVelocity_;
    float yVelocity_;
};

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
