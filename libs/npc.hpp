#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"

class Npc : public GameObject
{
public:
    Npc(float x, float y, sf::Color color);
    void draw(sf::RenderTarget* target) override;
    void update(sf::Vector2u targetSize) override;

private:
    sf::CircleShape shape_;
    sf::Vector2f position_;
    sf::Vector2f velocity_ = {0.f, 0.f};
    sf::Vector2f accel_ = {0.f, 0.098f};
};
