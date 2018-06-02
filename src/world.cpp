
#include "world.h"

World::World() : world(b2Vec2(0.f, 10.f))
{
}

World::World(b2Vec2 gravity) : world(gravity)
{
}
