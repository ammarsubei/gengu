/**
 *  @file Dynamic body class definitions
 *
 *  @author Ammar Subei
 */

#include "dynamicBody.h"

DynamicBody::DynamicBody(const float xPos, const float yPos) : Body(xPos, yPos, Type::DYNAMIC)
{
  // This size and shape is temporary for testing
  setSize(40, 40);
  setDensity(1.f);
  setFriction(0.3f);
  shape = new sf::CircleShape(size.x / 2);

  shape->setOrigin(size.x / 2, size.y / 2);
  shape->setPosition(position);
}

void DynamicBody::update()
{
  shape->setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
  shape->setRotation(body->GetAngle() * 180 / b2_pi);
}
