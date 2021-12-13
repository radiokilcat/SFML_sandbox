#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"

class Player : public GameObject
{
public:
    Player(float x, float y, sf::Color color);
    void draw(sf::RenderTarget* target);
};
