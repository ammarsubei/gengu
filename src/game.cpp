/**
 *  @file Game class definitions
 *
 *  @author Ammar Subei
 */

#include "game.h"
#include "staticBody.h"
#include "dynamicBody.h"

Game::Game(b2Vec2 grav) : world(grav)
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
      spawnBody(Body::Type::DYNAMIC);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      spawnBody(Body::Type::STATIC);
    }
  }
}

void Game::update()
{
  world.Step(1 / 60.f, 8, 3);

  for (auto body : bodies) {
    body->update();
  }
}

void Game::render()
{
  sf::Color background(0, 0, 0);
  window.clear(background);

  for (auto body : bodies) {
    window.draw(body->getShape());
  }

  window.display();
}

void Game::spawnBody(Body::Type t)
{
  Body *newBody;
  const float xPos = sf::Mouse::getPosition(window).x;
  const float yPos = sf::Mouse::getPosition(window).y;

  switch(t) {
    case Body::Type::DYNAMIC:
      newBody = new DynamicBody(xPos, yPos);
      break;
    case Body::Type::STATIC:
      newBody = new StaticBody(xPos, yPos);
      break;
    default:
      break;
  }
  newBody->createBody(world);
  bodies.push_back(newBody);
}
