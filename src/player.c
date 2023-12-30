#include "../include/player.h"

void player_init(Player *player) {
  Projection_Plane *make_plane = malloc(sizeof(Projection_Plane));
  if (make_plane == NULL) {
    // Handle memory allocation failure
    exit(EXIT_FAILURE);
  }
  // make_plane->x = 0;
  // make_plane->y = 0;
  // make_plane->z = 50;
  make_plane->pos[0] = 0;
  make_plane->pos[1] = 0;
  make_plane->pos[2] = 50;
  make_plane->width = 80;
  make_plane->height = 60;
  init_screen(make_plane);
  player->plane = make_plane;

  player->clean_up = player_clean_up;
}

void player_clean_up(Player *player) { free(player->plane); }
