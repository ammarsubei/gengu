/**
 *  @file Static body class definitions
 *
 *  @author Ammar Subei
 */

#include "staticBody.h"

StaticBody::StaticBody(const float xPos, const float yPos) : Body(xPos, yPos, Type::STATIC)
{
  // This size and shape is temporary for testing
  setSize(800, 100);
  setDensity(0.f);
  setFriction(1.f);
  shape = new sf::RectangleShape(size);

  shape->setOrigin(size.x / 2, size.y / 2);
  shape->setPosition(position);
}
