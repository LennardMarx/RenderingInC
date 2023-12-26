#include "../include/projector.h"

void project_cube(Cube *cube, Focal *focal, Screen *screen) {

  for (int i = 0; i < 8; i++) {

    float dir[3] = {cube->corners[i][0] - focal->x,
                    cube->corners[i][1] - focal->y,
                    cube->corners[i][2] - focal->z};

    float t = screen->z / cube->corners[i][2];
    // printf("Intersection z: %f\n", t);

    float intersection[2] = {t * dir[0], t * dir[1]}; //, t * dir[2]};
    // printf("Screen corner:  %f, %f, %f\n", intersection[0],
    // intersection[1], intersection[2]);

    cube->screen_pos[i][0] =
        (intersection[0] + (float)screen->width / 2) * WIDTH / screen->width;
    cube->screen_pos[i][1] =
        (intersection[1] + (float)screen->heigth / 2) * HEIGHT / screen->heigth;
    // printf("Screen pos: %d, %d:\n", screen_pos[i][0], screen_pos[i][1]);
  }
}
