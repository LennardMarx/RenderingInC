#include "../include/screen_plane.h"

void init_screen(Screen *screen) {
  screen->corners = malloc(4 * sizeof(int *));
  for (int i = 0; i < 8; i++)
    screen->corners[i] = malloc(3 * sizeof(int));

  screen->corners[0][0] = screen->x - (float)screen->width / 2;
  screen->corners[0][1] = screen->y - (float)screen->heigth / 2;
  screen->corners[0][2] = screen->z;

  screen->corners[1][0] = screen->x + (float)screen->width / 2;
  screen->corners[1][1] = screen->y - (float)screen->heigth / 2;
  screen->corners[1][2] = screen->z;

  screen->corners[2][0] = screen->x + (float)screen->width / 2;
  screen->corners[2][1] = screen->y + (float)screen->heigth / 2;
  screen->corners[2][2] = screen->z;

  screen->corners[3][0] = screen->x - (float)screen->width / 2;
  screen->corners[3][1] = screen->y + (float)screen->heigth / 2;
  screen->corners[3][2] = screen->z;
}
