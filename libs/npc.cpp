#include "npc.hpp"

Npc::Npc(float x, float y, sf::Color color)
//    : GameObject(x, y, sf::Color)
    : shape_{sf::CircleShape(10.f)}
    , position_(x, y)
{
    shape_.setFillColor(color);
}

void Npc::draw(sf::RenderTarget* target)
{
    target->draw(shape_);
}

void Npc::update(sf::Vector2u targetSize)
{
    if (position_.x <= targetSize.x / 2 &&
        position_.y <= targetSize.y / 2)
    {
        velocity_ += accel_;
        position_ += velocity_;
    }
    shape_.setPosition(position_);
}
