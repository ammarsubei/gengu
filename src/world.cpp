
#include "world.h"

World::World(b2Vec2 gravity) : world(gravity)
{
}

void World::step()
{
  world.Step(1 / 60.f, 8, 3);

  for (auto body : bodies) {
    body.update();
  }
}

void World::spawnBody(const float x, const float y)
{
  Body newBody(x, y);
  newBody.createBody(world, true);
  bodies.push_back(newBody);
}
