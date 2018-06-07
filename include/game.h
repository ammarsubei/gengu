/**
 *  @file Game class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Box2D.h"
#include "body.h"

/**
 *  @brief Game class header file
 */
class Game
{
  public:
    /**
     *  @brief Default constructor
     *  @param b2Vec2 gravity
     */
    Game(b2Vec2 grav = b2Vec2(0.f, 10.f));

    /**
     *  @brief Runs game
     */
    void run();

  private:
    /**
     *  @brief Handles events and input
     */
    void events();

    /**
     *  @brief Updates game state and objects
     */
    void update();

    /**
     *  @brief Renders game visuals and textures
     */
    void render();

    /**
     *  @brief Spawns new body
     *  @param Body::Type body type
     */
    void spawnBody(Body::Type t);

  private:
    b2World world;              ///< Game physics world
    sf::RenderWindow window;    ///< Game window instance
    std::vector<Body*> bodies;  ///< List of bodies in the game
};
