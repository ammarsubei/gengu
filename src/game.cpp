/**
 *  @file Game class definitions
 *
 *  @author Ammar Subei
 */

#include "game.h"
#include "staticBody.h"
#include "dynamicBody.h"

sf::Texture Game::dyno;
sf::Texture Game::stat;

Game::Game(b2Vec2 grav) : world(grav)
{
  // Temporary textures and sizes
  if (!dyno.loadFromFile("2.jpg", sf::IntRect(500,500,20,20))) {
    exit(100);
  }

  if (!stat.loadFromFile("2.jpg", sf::IntRect(20,50,800,100))) {
    exit(100);
  }

  // Anti-aliasing
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  window.create(sf::VideoMode::getDesktopMode(), "Gengu", sf::Style::Default, settings);

  // Vertical sync and 60 fps
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
  sf::Color background(50, 50, 50);
  window.clear(background);

  for (auto body : bodies) {
    window.draw(body->getShape());
  }

  window.display();
}

void Game::spawnBody(Body::Type t)
{
  const float xPos = sf::Mouse::getPosition(window).x;
  const float yPos = sf::Mouse::getPosition(window).y;

  Body *newBody;
  switch(t) {
    case Body::Type::DYNAMIC:
      newBody = new DynamicBody(xPos, yPos);
      newBody->getShape().setTexture(&dyno);
      break;
    case Body::Type::STATIC:
      newBody = new StaticBody(xPos, yPos);
      newBody->getShape().setTexture(&stat);
      break;
    default:
      break;
  }

  newBody->createBody(world);
  bodies.push_back(newBody);
}
