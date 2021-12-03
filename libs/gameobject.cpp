#include "gameobject.hpp"


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
