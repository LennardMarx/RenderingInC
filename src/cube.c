#include "../include/cube.h"

void init_cube(Cube *cube) {
  // (*cube->corners)[3] = malloc(8 * sizeof(*cube->corners));
  cube->corners = malloc(8 * sizeof(int *));
  for (int i = 0; i < 8; i++)
    cube->corners[i] = malloc(3 * sizeof(int));
  update_corners(cube);
}

void update_corners(Cube *cube) {

  cube->corners[0][0] = cube->x - cube->side_length / 2;
  cube->corners[0][1] = cube->y - cube->side_length / 2;
  cube->corners[0][2] = cube->z - cube->side_length / 2;

  cube->corners[1][0] = cube->x + cube->side_length / 2;
  cube->corners[1][1] = cube->y - cube->side_length / 2;
  cube->corners[1][2] = cube->z - cube->side_length / 2;

  cube->corners[2][0] = cube->x + cube->side_length / 2;
  cube->corners[2][1] = cube->y + cube->side_length / 2;
  cube->corners[2][2] = cube->z - cube->side_length / 2;

  cube->corners[3][0] = cube->x - cube->side_length / 2;
  cube->corners[3][1] = cube->y + cube->side_length / 2;
  cube->corners[3][2] = cube->z - cube->side_length / 2;

  cube->corners[4][0] = cube->x - cube->side_length / 2;
  cube->corners[4][1] = cube->y - cube->side_length / 2;
  cube->corners[4][2] = cube->z + cube->side_length / 2;

  cube->corners[5][0] = cube->x + cube->side_length / 2;
  cube->corners[5][1] = cube->y - cube->side_length / 2;
  cube->corners[5][2] = cube->z + cube->side_length / 2;

  cube->corners[6][0] = cube->x + cube->side_length / 2;
  cube->corners[6][1] = cube->y + cube->side_length / 2;
  cube->corners[6][2] = cube->z + cube->side_length / 2;

  cube->corners[7][0] = cube->x - cube->side_length / 2;
  cube->corners[7][1] = cube->y + cube->side_length / 2;
  cube->corners[7][2] = cube->z + cube->side_length / 2;
}
