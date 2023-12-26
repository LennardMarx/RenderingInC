#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h>

typedef struct {
  float x, y, z;
  float side_length;
  float **corners;
  int screen_pos[8][2];
} Cube;

void init_cube(Cube *cube);

void update_corners(Cube *cube);

#endif
