#include "game.hpp"

Game::Game(sf::RenderWindow* window)
    :window_(window)
{

}

void Game::run()
{
      while (window_->isOpen())
      {
          sf::Event event;
          while (window_->pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window_->close();
          }
          window_->display();
          for(auto& object: game_objects_)
          {
              object.move();
              window_->draw(object.shape_);
          }
      }

}

void Game::add_game_object(GameObject game_object)
{
    game_objects_.push_back(game_object);
}

GameObject::GameObject(float x, float y, float xVelocity, float yVelocity, sf::Color color)
    : x_(x),
      y_(y),
      xVelocity_(xVelocity),
      yVelocity_(yVelocity),
      shape_{sf::CircleShape(10.f)}
{
    shape_.setFillColor(color);
    shape_.setPosition(x, y);
}

float GameObject::x() const
{
    return x_;
}

void GameObject::setX(float x)
{
    x_ = x;
}

float GameObject::y() const
{
    return y_;
}

void GameObject::setY(float y)
{
    y_ = y;
}

float GameObject::xVelocity() const
{
    return xVelocity_;
}

void GameObject::setXVelocity(float xVelocity)
{
    xVelocity_ = xVelocity;
}

float GameObject::yVelocity() const
{
    return yVelocity_;
}

void GameObject::setYVelocity(float yVelocity)
{
    yVelocity_ = yVelocity;
}

void GameObject::move()
{
    shape_.move(xVelocity_, yVelocity_);
}

