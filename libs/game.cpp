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
              if (event.type == sf::Event::KeyPressed)
                  handleKey();
          }
          for(auto& object: game_objects_)
              object->draw(window_);
          for(auto& object: game_objects_)
              object->update(window_->getSize());
          window_->display();
          window_->clear();
      }
}

void Game::add_game_object(GameObject* game_object)
{
    game_objects_.push_back(game_object);
}

void Game::add_player(Player* player)
{
    player_ = player;
    game_objects_.push_back(player_);
}

void Game::handleKey()
{
    for (auto it: game_objects_)
    {
        if(it != player_)
            if (player_->checkCollisions(it))
                return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player_->move(-5.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player_->move(5.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player_->move(0.f, -5.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player_->move(0.f, 5.f);
}
