#include "../include/event_handler.h"

void handle_events_function(SDL_Event *event, SDL_Rect *r, int *quit,
                            Cube *cube) {
  while (SDL_PollEvent(event) != 0) {
    if (event->type == SDL_QUIT) {
      *quit = 1;
    } else if (event->type == SDL_KEYDOWN) {
      // Key pressed
      switch (event->key.keysym.sym) {
      case SDLK_ESCAPE:
        *quit = 1; // Quit the loop if the Escape key is pressed
        break;
      case SDLK_q:
        *quit = 1;
        break;
      case SDLK_DOWN:
        r->y += 10;
        cube->z -= 3;
        break;
      case SDLK_UP:
        r->y -= 10;
        cube->z += 3;
        break;
      case SDLK_RIGHT:
        r->x += 10;
        break;
      case SDLK_LEFT:
        r->x -= 10;
        break;
      case SDLK_s:
        r->y += 10;
        cube->y += 3;
        break;
      case SDLK_w:
        r->y -= 10;
        cube->y -= 3;
        break;
      case SDLK_d:
        r->x += 10;
        cube->x += 3;
        break;
      case SDLK_a:
        r->x -= 10;
        cube->x -= 3;
        break;
      }
    }
  }
}

void init_event_handler(EventHandler *event_handler) {
  event_handler->handle_events = handle_events_function;
}
