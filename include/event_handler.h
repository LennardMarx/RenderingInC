
#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "../include/cube.h"
#include "../include/world.h"
#include <SDL2/SDL.h>
#include <math.h>

// typedef struct interface Interface;
typedef struct {
  void (*handle_events)(SDL_Event *event, SDL_Rect *r, int *quit, Cube *cube,
                        World *world);
} EventHandler;

void handle_events_function(SDL_Event *event, SDL_Rect *r, int *quit,
                            Cube *cube, World *world);

void init_event_handler(EventHandler *event_handler);

#endif
