#ifndef WORLD_H
#define WORLD_H

#include <math.h>
struct World;

typedef struct World {
  float pos[3];
  float pos_ref[3];
  float rot[3];
  float jump[17];
  int jump_it;
  void (*update)(struct World *world);
  void (*rotate_y)(struct World *world);
} World;

void init_world(World *world);

void update_world(World *world);

void rotate_world_y(World *world);

#endif
