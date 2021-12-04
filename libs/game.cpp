#include "game.hpp"
#include <iostream>

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
              if (event.type != sf::Event::KeyPressed)
                  player_->stop();
              else
                  handleKey();
          }
          for(auto& object: game_objects_)
          {
              object->update(window_->getSize());
              detect_collision();

              track_object(object);
              object->draw(window_);
          }

          window_->display();
          window_->clear();
      }
}

void Game::add_game_object(GameObject* game_object)
{
    game_objects_.push_back(game_object);
    object_tracking_[game_object->getId()] = game_object->getPosition();

}

void Game::set_player(Player* player)
{
    player_ = player;
}

void Game::track_object(GameObject* game_object)
{
    object_tracking_[game_object->getId()] = game_object->getPosition();
}

void Game::handleKey()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player_->move(sf::Vector2f{-5.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player_->move(sf::Vector2f{5.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player_->move(sf::Vector2f{0.f, -5.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player_->move(sf::Vector2f{0.f, 5.f});
}


void Game::handle_collision(GameObject* a, GameObject* b)
{
    a->setPosition(object_tracking_.at(a->getId()));
    b->setPosition(object_tracking_.at(b->getId()));

    a->stop();
    b->stop();
}

bool Game::detect_collision()
{
    for (auto it: game_objects_)
    {
        sf::FloatRect bounds = it->getGlobalBounds();
        if (it == player_)
        for (auto it1: game_objects_)
        {
            if (it1 == it)
                continue;
            sf::FloatRect it1_bounds = it1->getGlobalBounds();
            if (bounds.intersects(it1_bounds))
            {
                std::cout << "handle collision" << std::endl;
                handle_collision(it, it1);
            }
        }
    }
    return false;
}
