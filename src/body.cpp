/**
 *  @file Body class definitions
 *
 *  @author Ammar Subei
 */

#include "body.h"

float Body::scale = 30.f;

void Body::update()
{
  shape->setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
  shape->setRotation(body->GetAngle() * 180 / b2_pi);
}
