#include "Physics.h"

Physics::Physics() = default;

const bool Physics::Intersect(Sprites& entity1, Sprites& entity2) {
   return entity1.hitbox.intersects(entity2.hitbox);
}
