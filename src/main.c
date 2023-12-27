#include "../include/cube.h"
#include "../include/definitions.h"
#include "../include/event_handler.h"
#include "../include/focal_point.h"
#include "../include/interface.h"
#include "../include/projector.h"
#include "../include/screen_plane.h"

#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv) {

  Interface UI;
  init_interface(&UI, WIDTH, HEIGHT);

  EventHandler event_handler;
  init_event_handler(&event_handler);

  SDL_Event event;
  int quit = 0;

  SDL_Rect r = {.x = WIDTH / 2 - 25, .y = HEIGHT / 2 - 25, .w = 50, .h = 50};

  Cube cube = {.pos = {0, 5, 50}, .side_length = 15, .angle_deg = 0};
  init_cube(&cube);

  Focal focal = {.x = 0, .y = 0, .z = 0};

  Screen screen = {.x = 0, .y = 0, .z = 25, .width = 80, .heigth = 60};
  init_screen(&screen);

  while (!quit) {
    // Handle events
    event_handler.handle_events(&event, &r, &quit, &cube);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 69, 133, 136, 255);

    // Clear winow
    SDL_RenderClear(UI.renderer);

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(UI.renderer, 255, 255, 255, 255);

    cube.angle_deg[0] += 1;
    cube.angle_deg[1] += 1;
    cube.angle_deg[2] += 1;

    cube.update(&cube);

    // Project cube to the screen plane.
    project_cube(&cube, &focal, &screen);

    // Draw the projected cube on the screen.
    UI.draw_cube(UI.renderer, &cube);

    // Update the screen
    SDL_RenderPresent(UI.renderer);

    // Add a small delay to control the frame rate (optional)
    SDL_Delay(16);
  }

  SDL_DestroyWindow(UI.window);
  SDL_Quit();

  // free(UI.window);
  // free(UI.renderer);
  // free(&UI);

  return 0;
}
