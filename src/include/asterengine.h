#ifndef ASTERENGINE_H
#define ASTERENGINE_H

#include "graphics.h"
#include "statemanager.h"

typedef struct {
  char *title;
  int width;
  int height;
} AsterOptions;

typedef struct {
  char quit;
  Graphics graphics;
  StateManager stateManager;
} AsterEngine;

int ae_init(AsterEngine *engine, AsterOptions *options);
int ae_free(AsterEngine *engine);

#endif // ASTER_H