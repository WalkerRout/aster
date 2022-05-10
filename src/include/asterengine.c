
#include <stdio.h>
#include <stdlib.h>

#include "asterengine.h"



int ae_init(AsterEngine *engine, AsterOptions *options){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  if(options != NULL){
    engine->graphics.width = options->width;
    engine->graphics.height = options->height;
    engine->graphics.title = options->title;
  }
  
  engine->quit = 0;

  if(g_init(&engine->graphics) == 1){
    printf("Error initializing graphics!\n");
    engine->quit = 1;
    return 1;
  }

  if(sm_init(&engine->stateManager) == 1){
    printf("Error initializing state manager!\n");
    engine->quit = 1;
    return 1;
  }

  return 0;
}



int ae_free(AsterEngine *engine){
  sm_free(&engine->stateManager);
  g_free(&engine->graphics);
  SDL_Quit();
  return 0;
}