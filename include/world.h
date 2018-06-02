/**
 *  @file World class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include "Box2D.h"

class World
{
  public:
    World();
    World(b2Vec2 gravity);

  private:
    b2World world;
};

