#include "../include/cube.h"
#include "../include/definitions.h"
#include "../include/event_handler.h"
#include "../include/focal_point.h"
#include "../include/interface.h"
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

  Cube cube = {.world_pos = {30, 0, 0}, .side_length = 15, .angle_deg = 0};
  init_cube(&cube);
  Cube cube2 = {.world_pos = {0, 0, 0}, .side_length = 15, .angle_deg = 0};
  init_cube(&cube2);

  Player player = {.pos = {0, -15, 0}, .rot = {0, 0, 0}};
  player_init(&player);

  World world = {.pos = {0, 0, 80},
                 .rot = {0, 0, 0},
                 .jump_it = 99,
                 .jump = {4, 3.5, 3, 2.5, 2, 1.5, 1, 0.5, 0, -0.5, -1, -1.5, -2,
                          -2.5, -3, -3.5, -4}};
  init_world(&world);

  while (!quit) {
    // Handle events
    event_handler.handle_events(&event, &r, &quit, &cube, &world);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 69, 133, 136, 255);

    // Clear winow
    SDL_RenderClear(UI.renderer);

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 255, 255, 255, 255);

    cube.update(&cube, &world);
    cube.angle_deg[1] = world.rot[1];
    cube2.update(&cube2, &world);
    cube2.angle_deg[1] = world.rot[1];

    // jump
    if (world.jump_it < 18) {
      world.pos[1] += world.jump[world.jump_it];
      world.jump_it++;
    }

    world.update(&world);

    // Project cube to the screen plane.
    // project_cube(&cube, &focal, player.plane);
    // project_cube(&cube2, &focal, player.plane);
    project_cube(&cube, &player);
    project_cube(&cube2, &player);

    // Draw the projected cube on the screen.
    UI.draw_cube(UI.renderer, &cube);
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
