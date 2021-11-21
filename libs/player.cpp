#include "player.hpp"

Player::Player(float x, float y, sf::Color color)
    : shape_(sf::CircleShape(10.f))
    , position_(x, y)
    , velocity_{0,0}
    , accel_{0,0}
{
}

void Player::draw(sf::RenderTarget* target)
{
    target->draw(shape_);
}

void Player::update(sf::Vector2u targetSize)
{
    if (position_.x <= targetSize.x / 2 &&
        position_.y <= targetSize.y / 2)
    {
        velocity_ += accel_;
        position_ += velocity_;
    }
    shape_.setPosition(position_);
}
