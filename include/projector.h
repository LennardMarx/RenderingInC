#ifndef PROJECTOR_H
#define PROJECTOR_H

#include "../include/cube.h"
#include "../include/definitions.h"
#include "../include/focal_point.h"
#include "../include/screen_plane.h"

void project_cube(Cube *cube, Focal *focal, Screen *screen);

#endif
