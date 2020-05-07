#ifndef SUNWHYSENGINE_PHYSICS_H
#define SUNWHYSENGINE_PHYSICS_H

#include "../Sprites/Sprites.h"

class Physics {
public:
  Physics();
  const bool Intersect(Sprites& entity1, Sprites& entity2);
};


#endif //SUNWHYSENGINE_PHYSICS_H
