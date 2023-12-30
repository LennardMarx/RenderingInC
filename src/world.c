#include "../include/world.h"

#include <stdio.h>

void init_world(World *world) {
  //
  // world->jump_it = 0;
  world->update = update_world;
  world->rotate_y = rotate_world_y;
}

void update_world(World *world) {
  world->rotate_y(world);
  //
}

void rotate_world_y(World *world) {
  float ang = world->rot[1] * M_PI / 180; // to radians
  // printf("ANGLE: %f\n", ang);
  //
  float new_pos[3];
  // Matrix multiplication.
  new_pos[0] = world->pos[0] * cosf(ang) + world->pos[2] * sinf(ang);
  new_pos[1] = world->pos[1];
  new_pos[2] = -world->pos[0] * sinf(ang) + world->pos[2] * cosf(ang);
  // world->pos[0] = new_pos[0];
  // world->pos[1] = new_pos[1];
  // world->pos[2] = new_pos[2];
  world->pos_ref[0] = new_pos[0];
  world->pos_ref[1] = new_pos[1];
  world->pos_ref[2] = new_pos[2];
}
