/**
 *  @file Static body class definitions
 *
 *  @author Ammar Subei
 */

#include "staticBody.h"

StaticBody::StaticBody(const float x, const float y) : Body(x, y, Type::STATIC)
{
  // This size and shape is temporary for testing
  setSize(800, 100);
  shape = new sf::RectangleShape(size);
  shape->setOrigin(size.x / 2, size.y / 2);
  shape->setPosition(position);
}

void StaticBody::createBody(b2World &world)
{
  b2BodyDef bodyDef;

  bodyDef.type = b2_staticBody;

  bodyDef.position.Set(position.x / scale, position.y / scale);
  body = world.CreateBody(&bodyDef);

  b2PolygonShape polygonShape;
  polygonShape.SetAsBox(
      shape->getLocalBounds().width / 2 / scale,
      shape->getLocalBounds().height / 2 / scale);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &polygonShape;
  fixtureDef.density = 0.f;
  fixtureDef.friction = 0.3f;
  body->CreateFixture(&fixtureDef);
}
