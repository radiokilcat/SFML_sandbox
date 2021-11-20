#include "game.hpp"

Game::Game(sf::RenderWindow* window)
    :window_(window)
{
}

void Game::run()
{
    sf::CircleShape experiment(10.f);
    sf::Vector2f increment(0.4f, 0.4f);
      while (window_->isOpen())
      {
          sf::Event event;
          while (window_->pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window_->close();
          }
          for(auto& object: game_objects_)
              object.draw(window_);
          for(auto& object: game_objects_)
              object.update(window_->getSize());
          window_->display();
          window_->clear();
      }
}

void Game::add_game_object(GameObject game_object)
{
    game_objects_.push_back(game_object);
}
