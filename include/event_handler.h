
#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "../include/cube.h"
#include <SDL2/SDL.h>

// typedef struct interface Interface;
typedef struct {
  void (*handle_events)(SDL_Event *event, SDL_Rect *r, int *quit, Cube *cube);
} EventHandler;

void handle_events_function(SDL_Event *event, SDL_Rect *r, int *quit,
                            Cube *cube);

void init_event_handler(EventHandler *event_handler);

#endif
