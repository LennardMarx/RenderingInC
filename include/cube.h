#ifndef CUBE_H
#define CUBE_H

#include "../include/world.h"
#include <math.h>
#include <stdlib.h>

struct Cube;

typedef struct Cube {
  float world_pos[3];
  float pos[3];
  float angle_deg[3];
  float side_length;
  float t;
  // float **corners;
  float corners[8][3];
  int screen_pos[8][2];
  void (*update)(struct Cube *cube, World *world);
  void (*update_corners)(struct Cube *cube);
  void (*update_pos)(struct Cube *cube, World *world);
  void (*rotate_x)(struct Cube *cube);
  void (*rotate_y)(struct Cube *cube, World *world);
  void (*rotate_z)(struct Cube *cube);
} Cube;

void init_cube(Cube *cube);

void update_cube(Cube *cube, World *world);

void update_pos(Cube *cube, World *world);
void update_corners(Cube *cube);

void rotate_x(Cube *cube);
void rotate_y(Cube *cube, World *world);
void rotate_z(Cube *cube);

#endif
