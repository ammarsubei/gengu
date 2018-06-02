
#include "body.h"

Body::Body(const float x, const float y) : position(x, y)
{
  size.x = 20;
  size.y = 20;
  shape = new sf::RectangleShape(size);
  shape->setOrigin(size.x / 2, size.y / 2);
  shape->setPosition(position);
}

void Body::createBody(b2World &world, bool dynamic)
{
  b2BodyDef bodyDef;

  if (dynamic) {
    bodyDef.type = b2_dynamicBody;
  }

  bodyDef.position.Set(position.x / scale, position.y / scale);
  body = world.CreateBody(&bodyDef);

  b2PolygonShape polygonShape;
  polygonShape.SetAsBox(shape->getLocalBounds().width / 2 / scale, shape->getLocalBounds().height / 2 / scale);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &polygonShape;
  fixtureDef.density = dynamic;
  fixtureDef.friction = 0.3f;
  body->CreateFixture(&fixtureDef);
}

void Body::update()
{
  shape->setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
  shape->setRotation(body->GetAngle() * 180 / b2_pi);
}
