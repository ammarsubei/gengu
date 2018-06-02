/**
 *  @file Game class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <SFML/Graphics.hpp>

#include "world.h"

class Game
{
  public:
    Game();

    void run();

  private:
    void events();
    void update();
    void render();

  private:
    sf::RenderWindow window;
    World world;
};
