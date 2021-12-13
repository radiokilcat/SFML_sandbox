#pragma once

#include "gameobject.hpp"

class BoxCollider : public GameObject
{
public:
    BoxCollider(float x, float y, float width, float height, sf::Color color);
    void draw(sf::RenderTarget* target);
};
