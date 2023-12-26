#ifndef SCREEN_PLANE_H
#define SCREEN_PLANE_H

#include <stdlib.h>

typedef struct {
  float x, y, z;
  int width;
  int heigth;
  float **corners;
} Screen;

void init_screen(Screen *screen);

#endif
