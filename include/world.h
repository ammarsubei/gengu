/**
 *  @file World class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <vector>

#include "Box2D.h"
#include "body.h"

class World
{
  public:
    World(b2Vec2 gravity = b2Vec2(0.f, 10.f));

    void step();
    void spawnBody(const float x, const float y);

    std::vector<Body>& getBodies() { return bodies; }

  private:
    b2World world;
    std::vector<Body> bodies;
};

