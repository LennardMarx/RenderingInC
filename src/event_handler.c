#include "../include/event_handler.h"

void handle_events_function(SDL_Event *event, SDL_Rect *r, int *quit,
                            Cube *cube, World *world) {
  while (SDL_PollEvent(event) != 0) {
    // User requests quit
    if (event->type == SDL_QUIT) {
      *quit = 1;
    }
  }
  // Set texture based on current keystate
  const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
  if (currentKeyStates[SDL_SCANCODE_W]) {
    world->pos[2] -= cosf(world->rot[1] * M_PI / 180) * 3;
    world->pos[0] += sinf(world->rot[1] * M_PI / 180) * 3;
  }
  if (currentKeyStates[SDL_SCANCODE_S]) {
    world->pos[2] += cosf(world->rot[1] * M_PI / 180) * 3;
    world->pos[0] -= sinf(world->rot[1] * M_PI / 180) * 3;
  }
  if (currentKeyStates[SDL_SCANCODE_A]) {
    world->pos[2] += sinf(world->rot[1] * M_PI / 180) * 3;
    world->pos[0] += cosf(world->rot[1] * M_PI / 180) * 3;
  }
  if (currentKeyStates[SDL_SCANCODE_D]) {
    world->pos[2] -= sinf(world->rot[1] * M_PI / 180) * 3;
    world->pos[0] -= cosf(world->rot[1] * M_PI / 180) * 3;
  }
  if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
    *quit = 1;
  }
  if (currentKeyStates[SDL_SCANCODE_Q]) {
    world->rot[1] += 2;
  }
  if (currentKeyStates[SDL_SCANCODE_E]) {
    world->rot[1] -= 2;
  }
  if (currentKeyStates[SDL_SCANCODE_SPACE]) {
    // world->jump_it = 0;
    world->pos[1] += 1;
  }
  if (currentKeyStates[SDL_SCANCODE_LSHIFT]) {
    world->pos[1] -= 1;
    // } else {
  }

  // while (SDL_PollEvent(event) != 0) {
  //   if (event->type == SDL_QUIT) {
  //     *quit = 1;
  //   } else if (event->type == SDL_KEYDOWN) {
  //     // Key pressed
  //     switch (event->key.keysym.sym) {
  //     case SDLK_ESCAPE:
  //       *quit = 1; // Quit the loop if the Escape key is pressed
  //       break;
  //     // case SDLK_q:
  //     //   *quit = 1;
  //     //   break;
  //     case SDLK_DOWN:
  //       r->y += 10;
  //       cube->pos[2] -= 3;
  //       break;
  //     case SDLK_UP:
  //       r->y -= 10;
  //       cube->pos[2] += 3;
  //       break;
  //     case SDLK_RIGHT:
  //       r->x += 10;
  //       break;
  //     case SDLK_LEFT:
  //       r->x -= 10;
  //       break;
  //     case SDLK_w:
  //       // r->y -= 10;
  //       // cube->pos[1] -= 3;
  //       world->pos[2] -= cosf(world->rot[1] * M_PI / 180) * 3;
  //       world->pos[0] += sinf(world->rot[1] * M_PI / 180) * 3;
  //       break;
  //     case SDLK_a:
  //       // r->x -= 10;
  //       // cube->pos[0] -= 3;
  //       // world->pos[0] += 3;
  //       world->pos[2] += sinf(world->rot[1] * M_PI / 180) * 3;
  //       world->pos[0] += cosf(world->rot[1] * M_PI / 180) * 3;
  //       break;
  //     case SDLK_s:
  //       // r->y += 10;
  //       // cube->pos[1] += 3;
  //       // world->pos[2] += 3;
  //       world->pos[2] += cosf(world->rot[1] * M_PI / 180) * 3;
  //       world->pos[0] -= sinf(world->rot[1] * M_PI / 180) * 3;
  //       break;
  //     case SDLK_d:
  //       // r->x += 10;
  //       // cube->pos[0] += 3;
  //       // world->pos[0] -= 3;
  //       world->pos[2] -= sinf(world->rot[1] * M_PI / 180) * 3;
  //       world->pos[0] -= cosf(world->rot[1] * M_PI / 180) * 3;
  //       break;
  //     case SDLK_q:
  //       // r->y += 10;
  //       // cube->pos[1] += 3;
  //       world->rot[1] += 3;
  //       break;
  //     case SDLK_e:
  //       // r->y += 10;
  //       // cube->pos[1] += 3;
  //       world->rot[1] -= 3;
  //       break;
  //     case SDLK_r:
  //       cube->angle_deg[0] += 3;
  //       break;
  //     case SDLK_t:
  //       cube->angle_deg[1] += 3;
  //       break;
  //     case SDLK_y:
  //       cube->angle_deg[2] += 3;
  //       break;
  //     case SDLK_SPACE:
  //       // world->pos[1] += 10;
  //       world->jump_it = 0;
  //       break;
  //     case SDLK_LSHIFT:
  //       world->pos[1] -= 10;
  //       break;
  //     }
  //   }
  // }
}

void init_event_handler(EventHandler *event_handler) {
  event_handler->handle_events = handle_events_function;
}
