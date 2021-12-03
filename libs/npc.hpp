#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"

class Npc : public GameObject
{
public:
    Npc(float x, float y, sf::Color color);
    void draw(sf::RenderTarget* target) override;
    sf::Vector2f get_velocity();

private:
};
