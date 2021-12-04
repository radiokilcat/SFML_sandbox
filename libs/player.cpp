#include "player.hpp"
#include <iostream>

Player::Player(float x, float y, sf::Color color)
    : GameObject(x, y, {new sf::CircleShape(20.f)})
{
    shape_->setFillColor(color);
}

void Player::draw(sf::RenderTarget* target)
{
    target->draw(*shape_);
}

//void Player::move(sf::Vector2f newPosition)
//{
//    static const float MAX_SPEED = 10;
//    std::cout << "move: new value: " << newPosition.x << " : " << newPosition.y << std::endl;
//    if (velocity_.x < MAX_SPEED && velocity_.x > -MAX_SPEED &&
//        velocity_.y < MAX_SPEED && velocity_.y > -MAX_SPEED)
//        velocity_ += newPosition;
//    std::cout << "move: velocity: " <<  velocity_.x << " : " << velocity_.y << std::endl;
//}
//void Player::stop()
//{
//    velocity_ = {0, 0};
//}

//sf::Vector2f Player::get_velocity()
//{
//    return velocity_;
//}
