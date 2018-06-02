/**
 *  @file Body class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Box2D.h"

class Body
{
  public:
    Body(const float x, const float y);

    sf::Shape& getShape() const { return *shape; }

    void createBody(b2World &world, bool dynamic);
    void update();

  private:
    sf::Texture texture;
    sf::Vector2f size;
    sf::Vector2f position;
    sf::Shape *shape;
    b2Body *body;

    const float scale = 30.f;
};

