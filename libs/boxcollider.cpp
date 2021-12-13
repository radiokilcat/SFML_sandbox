#include "boxcollider.hpp"

BoxCollider::BoxCollider(float x, float y, float width, float height, sf::Color color)
    : GameObject(x, y, {new sf::RectangleShape(sf::Vector2f{width, height})}, "player")
{
    shape_->setFillColor(color);
}

void BoxCollider::draw(sf::RenderTarget* target)
{
    target->draw(*shape_);
}
