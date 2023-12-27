#ifndef CUBE_H
#define CUBE_H

#include <math.h>
#include <stdlib.h>

struct Cube;

typedef struct Cube {
  float pos[3];
  float angle_deg[3];
  float side_length;
  // float **corners;
  float corners[8][3];
  int screen_pos[8][2];
  void (*update)(struct Cube *cube);
  void (*update_corners)(struct Cube *cube);
  void (*rotate_x)(struct Cube *cube);
  void (*rotate_y)(struct Cube *cube);
  void (*rotate_z)(struct Cube *cube);
} Cube;

void init_cube(struct Cube *cube);

void update_cube(struct Cube *cube);

void update_corners(struct Cube *cube);

void rotate_x(struct Cube *cube);
void rotate_y(struct Cube *cube);
void rotate_z(struct Cube *cube);

#endif
