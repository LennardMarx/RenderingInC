#ifndef SCREEN_PLANE_H
#define SCREEN_PLANE_H

#include <stdlib.h>

typedef struct {
  // float x, y, z;
  float pos[3];
  int width;
  int height;
  // float **corners;
  float corners[4][3];
} Projection_Plane;

void init_screen(Projection_Plane *plane);

#endif
