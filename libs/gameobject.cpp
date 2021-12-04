#include "gameobject.hpp"
#include <iostream>


GameObject::GameObject(float x, float y, sf::Shape* shape)
  : position_{x, y}
  , shape_{shape}
{
}

void GameObject::update(sf::Vector2u targetSize)
{
    velocity_ += accel_;
    position_ += velocity_;
    shape_->setPosition(position_);
}

sf::FloatRect GameObject::getGlobalBounds()
{
    return shape_->getGlobalBounds();
}

sf::Vector2f GameObject::getVelocity()
{
    return velocity_;
}

void GameObject::setPosition(sf::Vector2f position)
{
    position_ = position;
}

sf::Vector2f GameObject::getPosition()
{
    return position_;
}

void GameObject::move(sf::Vector2f velocity)
{
    static const float MAX_SPEED = 10;
    if (velocity_.x < MAX_SPEED && velocity_.x > -MAX_SPEED &&
        velocity_.y < MAX_SPEED && velocity_.y > -MAX_SPEED)
        velocity_ += velocity;
}

void GameObject::stop()
{
    velocity_ = {0, 0};
}
