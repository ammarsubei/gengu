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

void StaticBody::createBody(b2World &world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(position.x / Body::scale, position.y / Body::scale);
  body = world.CreateBody(&bodyDef);

  b2PolygonShape polygonShape;
  polygonShape.SetAsBox(
      shape->getLocalBounds().width / 2 / Body::scale,
      shape->getLocalBounds().height / 2 / Body::scale);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &polygonShape;
  fixtureDef.density = getDensity();
  fixtureDef.friction = getFriction();
  body->CreateFixture(&fixtureDef);
}
