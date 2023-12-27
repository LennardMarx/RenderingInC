#ifndef SCREEN_PLANE_H
#define SCREEN_PLANE_H

#include <stdlib.h>

typedef struct {
  float x, y, z;
  int width;
  int heigth;
  // float **corners;
  float corners[4][3];
} Screen;

void init_screen(Screen *screen);

#endif
