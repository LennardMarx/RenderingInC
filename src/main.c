#include "../include/cube.h"
#include "../include/definitions.h"
#include "../include/event_handler.h"
#include "../include/focal_point.h"
#include "../include/interface.h"
#include "../include/matrices.h"
#include "../include/player.h"
#include "../include/projection_plane.h"
#include "../include/projector.h"
#include "../include/world.h"

#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv) {

  Interface UI;
  init_interface(&UI, WIDTH, HEIGHT);

  EventHandler event_handler;
  init_event_handler(&event_handler);

  SDL_Event event;
  int quit = 0;
  SDL_Event events[100];
  int event_counter = 0;

  SDL_Rect r = {.x = WIDTH / 2 - 25, .y = HEIGHT / 2 - 25, .w = 50, .h = 50};

  Cube cube = {.pos = {30, 0, 80}, .side_length = 30, .angle_deg = 0};
  init_cube(&cube);
  Cube cube2 = {.pos = {30, -30, 80}, .side_length = 15, .angle_deg = 0};
  init_cube(&cube2);
  Cube cube3 = {.pos = {0, 0, 80}, .side_length = 30, .angle_deg = 0};
  init_cube(&cube3);
  Cube cube4 = {.pos = {60, 0, 80}, .side_length = 30, .angle_deg = 0};
  init_cube(&cube4);

  Player player = {.pos = {0, 0, 0}, .rot = {0, 0, 0}};
  player_init(&player);

  World world = {.pos = {0, 0, 80},
                 .rot = {0, 0, 0},
                 .jump_it = 99,
                 .jump = {4, 3.5, 3, 2.5, 2, 1.5, 1, 0.5, 0, -0.5, -1, -1.5, -2,
                          -2.5, -3, -3.5, -4}};
  init_world(&world);

  Matrix3x3 rot_mat = get_rotation_matrix(67, 23, 196);

  printf("Combined Rotation Matrix:\n");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      printf("%d%d  %f ", i, j, rot_mat.m[i][j]);
    }
    printf("\n");
  }

  while (!quit) {
    // Handle events
    event_handler.handle_events(&event, &r, &quit, &cube, &world, &player);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 69, 133, 136, 255);

    // Clear winow
    SDL_RenderClear(UI.renderer);

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 255, 255, 255, 255);

    player.update(&player);
    printf("Player pos: %f %f, %f \n", player.pos[0], player.pos[1],
           player.pos[2]);
    // printf("Plane pos: %f %f, %f \n", player.plane->pos[0],
    // player.plane->pos[1],
    //        player.plane->pos[2]);
    printf("Plane centroid: %f, %f, %f. \n", player.plane->centroid[0],
           player.plane->centroid[1], player.plane->centroid[2]);
    // printf("Plane Normal: %f, %f, %f. \n", player.plane->normal[0],
    //        player.plane->normal[1], player.plane->normal[2]);
    // printf("Player rot: %f, %f, %f. \n", player.rot[0], player.rot[1],
    //        player.rot[2]);
    // printf("Plane rot: %f, %f, %f. \n", player.plane->rot[0],
    //        player.plane->rot[1], player.plane->rot[2]);
    // printf("Corner Pos Ref: %f, %f, %f. \n", player.plane->corners_ref[0][0],
    //        player.plane->corners_ref[0][1], player.plane->corners_ref[0][2]);
    // printf("Corner Pos: %f, %f, %f. \n", player.plane->corners[0][0],
    //        player.plane->corners[0][1], player.plane->corners[0][2]);
    // printf("Cube Pos: %f, %f, %f. \n", cube.pos[0], cube.pos[1],
    // cube.pos[2]);

    cube2.angle_deg[0] -= 1;
    cube2.angle_deg[2] -= 1;
    // cube.angle_deg[0] += 1;

    cube.update(&cube);
    cube3.update(&cube3);
    cube4.update(&cube4);
    // cube.angle_deg[1] = world.rot[1];
    cube2.update(&cube2);
    // cube2.angle_deg[1] = world.rot[1];

    // jump
    if (world.jump_it < 18) {
      world.pos[1] += world.jump[world.jump_it];
      world.jump_it++;
    }

    // world.update(&world);

    // Project cube to the screen plane.
    project_cube(&cube, &player);
    project_cube(&cube3, &player);
    project_cube(&cube4, &player);
    project_cube(&cube2, &player);

    // Draw the projected cube on the screen.
    UI.draw_cube(UI.renderer, &cube);
    UI.draw_cube(UI.renderer, &cube3);
    UI.draw_cube(UI.renderer, &cube4);
    UI.draw_cube(UI.renderer, &cube2);

    // Update the screen
    SDL_RenderPresent(UI.renderer);

    // Add a small delay to control the frame rate (optional)
    SDL_Delay(16);
  }

  // Clean up
  player.clean_up(&player);

  SDL_DestroyWindow(UI.window);
  SDL_Quit();

  return 0;
}
