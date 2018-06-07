/**
 *  @file Dynamic body class definitions
 *
 *  @author Ammar Subei
 */

#include "dynamicBody.h"

DynamicBody::DynamicBody(const float x, const float y) : Body(x, y, Type::DYNAMIC)
{
  // This size and shape is temporary for testing
  setSize(20, 20);
  shape = new sf::RectangleShape(size);
  shape->setOrigin(size.x / 2, size.y / 2);
  shape->setPosition(position);
}

void DynamicBody::createBody(b2World &world)
{
  b2BodyDef bodyDef;

  bodyDef.type = b2_dynamicBody;

  bodyDef.position.Set(position.x / scale, position.y / scale);
  body = world.CreateBody(&bodyDef);

  b2PolygonShape polygonShape;
  polygonShape.SetAsBox(
      shape->getLocalBounds().width / 2 / scale,
      shape->getLocalBounds().height / 2 / scale);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &polygonShape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  body->CreateFixture(&fixtureDef);
}
