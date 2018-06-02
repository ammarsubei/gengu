
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
    update();
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

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      const float mouseX = sf::Mouse::getPosition(window).x;
      const float mouseY = sf::Mouse::getPosition(window).y;
      world.spawnBody(mouseX, mouseY);
    }
  }
}

void Game::update()
{
  world.step();
}

void Game::render()
{
  sf::Color background(0, 0, 0);
  window.clear(background);

  for (auto body : world.getBodies()) {
    window.draw(body.getShape());
  }

  window.display();
}
