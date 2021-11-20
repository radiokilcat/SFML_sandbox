#include "gameobject.hpp"
#include <iostream>

GameObject::GameObject(float x, float y, sf::Color color)
    : shape_{sf::CircleShape(10.f)},
      position_{x, y}
{
    shape_.setFillColor(color);
}

void GameObject::move(float dx, float dy)
{
    shape_.move(dx, dy);
}

void GameObject::draw(sf::RenderTarget* target)
{
    target->draw(shape_);
}

void GameObject::update(sf::Vector2u targetSize)
{
    if (shape_.getPosition().x <= targetSize.x / 2 ||
        shape_.getPosition().y <= targetSize.y / 2)
    {
        velocity_ += accel_;
        position_ += velocity_;
    }
    shape_.setPosition(position_);
}

sf::CircleShape GameObject::shape() const
{
    return shape_;
}
