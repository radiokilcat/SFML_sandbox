#include "npc.hpp"

Npc::Npc(float x, float y, sf::Color color)
    : GameObject(x, y, new sf::CircleShape(20.f), "npc")
{
    shape_->setFillColor(color);
}

void Npc::draw(sf::RenderTarget* target)
{
    target->draw(*shape_);
}
