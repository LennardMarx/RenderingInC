#include "../include/cube.h"
#include "../include/definitions.h"
#include "../include/event_handler.h"
#include "../include/interface.h"
#include "../include/player.h"
#include "../include/projector.h"

#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv) {

  Interface UI;
  init_interface(&UI, WIDTH, HEIGHT);

  EventHandler event_handler;
  init_event_handler(&event_handler);

  SDL_Event event;
  int quit = 0;

  Cube *cube = new_cube((float[]){30, 0, 80}, 30);
  Cube *cube2 = new_cube((float[]){30, 0, 80}, 15);
  Cube *cube3 = new_cube((float[]){-30, 0, 80}, 30);
  Cube *cube4 = new_cube((float[]){60, 0, 80}, 30);

  Player *player = new_player((float[]){0, 0, 0});

  while (!quit) {
    // Handle events
    event_handler.handle_events(&event, &quit, player);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 69, 133, 136, 255);

    // Clear winow
    SDL_RenderClear(UI.renderer);

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 255, 255, 255, 255);

    player->update(player);

    cube2->rot[0] -= 1;
    cube2->rot[2] -= 1;

    // Upate corner position of cube and rotate them.
    cube->update(cube);
    cube2->update(cube2);
    cube3->update(cube3);
    cube4->update(cube4);

    // Project cube to the screen plane.
    project_cube(cube, player);
    project_cube(cube2, player);
    project_cube(cube3, player);
    project_cube(cube4, player);

    // Draw the projected cube on the screen.
    UI.draw_cube(UI.renderer, cube);
    UI.draw_cube(UI.renderer, cube2);
    UI.draw_cube(UI.renderer, cube3);
    UI.draw_cube(UI.renderer, cube4);

    // printf("Player Rotation: %f\n", player->rot[1]);
    // printf("Player Position: %f, %f, %f\n", player->pos[0], player->pos[1],
    //        player->pos[2]);
    // printf("Plane centroid: %f, %f, %f\n", player->plane->centroid[0],
    //        player->plane->centroid[1], player->plane->centroid[2]);
    // printf("Player Posish: %f, %f, %f\n", player->pos[0], player->pos[1],
    //        player->pos[2]);
    // printf("Player rotish: %f, %f, %f\n", player->rot[0], player->rot[1],
    //        player->rot[2]);
    // printf("Plane Norm: %f, %f, %f\n", player->plane->normal[0],
    //        player->plane->normal[1], player->plane->normal[2]);
    // for (int i = 0; i < 4; i++) {
    //
    //   printf("Plane Corner [%d]: %f, %f, %f\n", i,
    //          player->plane->corners_ref[i][0],
    //          player->plane->corners_ref[i][1],
    //          player->plane->corners_ref[i][2]);
    // }
    // printf("Plane centroid: %f, %f, %f\n", player->plane->centroid[0],
    //        player->plane->centroid[1], player->plane->centroid[2]);

    // Update the screen
    SDL_RenderPresent(UI.renderer);

    // Add a small delay to control the frame rate (optional)
    SDL_Delay(16);
  }

  SDL_DestroyWindow(UI.window);
  SDL_Quit();

  // Clean up
  destroy_player(player);

  destroy_cube(cube);
  destroy_cube(cube2);
  destroy_cube(cube3);
  destroy_cube(cube4);
  // destroy_interface(&UI);

  return 0;
}
