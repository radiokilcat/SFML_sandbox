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
          for(auto& object: game_objects_)
          {
              window_->draw(object.shape());
              object.move(1, 1);
          }
          window_->display();
      }

}

void Game::add_game_object(GameObject game_object)
{
    game_objects_.push_back(game_object);
}
