#include "player.hpp"
#include <iostream>

Player::Player(float x, float y, sf::Color color)
    : GameObject(x, y, {new sf::CircleShape(20.f)}, "player")
{
    shape_->setFillColor(color);
}

void Player::draw(sf::RenderTarget* target)
{
    target->draw(*shape_);
}
