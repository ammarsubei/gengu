
#include "game.h"

Game::Game()
{
  window.create(sf::VideoMode::getDesktopMode(), "Gengu", sf::Style::Default);
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);
}

void Game::run()
{
  while ( window.isOpen() ) {
    events();
    //update();
    render();
  }
}

void Game::events()
{
  sf::Event event;
  while ( window.pollEvent(event) ) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void Game::render()
{
  sf::Color background(100, 100, 100);
  window.clear(background);
  window.display();
}
