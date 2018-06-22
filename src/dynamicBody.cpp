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

void DynamicBody::createBody(b2World &world)
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(position.x / Body::scale, position.y / Body::scale);
  body = world.CreateBody(&bodyDef);

  b2CircleShape circle;
  circle.m_radius = shape->getLocalBounds().width / 2 / Body::scale;

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &circle;
  fixtureDef.density = getDensity();
  fixtureDef.friction = getFriction();
  body->CreateFixture(&fixtureDef);
}

void DynamicBody::update()
{
  shape->setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
  shape->setRotation(body->GetAngle() * 180 / b2_pi);
}
