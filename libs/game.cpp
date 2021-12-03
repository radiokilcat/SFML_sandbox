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
              if (event.type != sf::Event::KeyPressed)
                  player_->stop();
              else
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
        sf::FloatRect bounds = it->getGlobalBounds();
        if (it == player_)
        for (auto it1: game_objects_)
        {
            if (it1 == it)
                continue;
            sf::FloatRect it1_bounds = it1->getGlobalBounds();
            if (bounds.intersects(it1_bounds))
                return;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player_->move(sf::Vector2f{-5.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player_->move(sf::Vector2f{5.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player_->move(sf::Vector2f{0.f, -5.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player_->move(sf::Vector2f{0.f, 5.f});
}

//bool Game::intersects(GameObject* a, GameObject* b)
//{

//}

void Game::handle_collision(GameObject* a, GameObject* b)
{
//    sf::Vector2f a_velocity = a;
//    sf::Vector2f b_velocity = b;

}
