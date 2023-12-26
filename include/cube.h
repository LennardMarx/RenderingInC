#ifndef CUBE_H
#define CUBE_H

#include <math.h>
#include <stdlib.h>

typedef struct {
  // float x, y, z;
  float angle_deg[3];
  float pos[3];
  float side_length;
  float **corners;
  int screen_pos[8][2];
} Cube;

void init_cube(Cube *cube);

void update_corners(Cube *cube);

// void rotate_cube(Cube *cube);

void rotate_x(Cube *cube);
void rotate_y(Cube *cube);
void rotate_z(Cube *cube);

#endif
