#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    virtual void draw(sf::RenderTarget* target) = 0;
    virtual void update(sf::Vector2u targetSize) = 0;
};

