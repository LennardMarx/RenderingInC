#include "../include/projector.h"

void project_cube(Cube *cube, Player *player) {
  // float test_dir[3] = {cube->pos[0] - focal->x, cube->pos[1] - focal->y,
  //                      cube->pos[2] - focal->z};

  cube->t = player->plane->pos[2] / cube->pos[2];
  // printf("Z Distance: %f\n", cube->pos[2]);
  for (int i = 0; i < 8; i++) {

    // Direction of corner to focal point.
    float dir[3] = {cube->corners[i][0] - player->pos[0],
                    cube->corners[i][1] - player->pos[1],
                    cube->corners[i][2] - player->pos[2]};

    // Multiplier of where the plane intersects on the line.
    float t = player->plane->pos[2] / cube->corners[i][2];

    // Intersection based on the Multiplier.
    float intersection[2] = {t * dir[0], t * dir[1]}; //, t * dir[2]};

    // Conversion from plane to plane size.
    cube->screen_pos[i][0] =
        (intersection[0] + (float)player->plane->width / 2) * WIDTH /
        player->plane->width;
    cube->screen_pos[i][1] =
        (intersection[1] + (float)player->plane->height / 2) * HEIGHT /
        player->plane->height;
  }
}

// void project_cube(Cube *cube, Player *player) {
//   // float test_dir[3] = {cube->pos[0] - focal->x, cube->pos[1] - focal->y,
//   //                      cube->pos[2] - focal->z};
//
//   cube->t = player->plane->pos[2] / cube->pos[2];
//   // printf("Z Distance: %f\n", cube->pos[2]);
//   for (int i = 0; i < 8; i++) {
//
//     // Direction of corner to focal point.
//     float dir[3] = {cube->corners[i][0] - player->pos[0],
//                     cube->corners[i][1] - player->pos[1],
//                     cube->corners[i][2] - player->pos[2]};
//
//     // Multiplier of where the plane intersects on the line.
//     float t = player->plane->pos[2] / cube->corners[i][2];
//
//     // Intersection based on the Multiplier.
//     float intersection[2] = {t * dir[0], t * dir[1]}; //, t * dir[2]};
//
//     // Conversion from plane to plane size.
//     cube->screen_pos[i][0] =
//         (intersection[0] + (float)player->plane->width / 2) * WIDTH /
//         player->plane->width;
//     cube->screen_pos[i][1] =
//         (intersection[1] + (float)player->plane->height / 2) * HEIGHT /
//         player->plane->height;
//   }
// }
