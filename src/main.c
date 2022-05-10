#include <stdio.h>
#include <stdlib.h>

#include "include/asterengine.h"

unsigned int initState1(){
  printf("State 1 created\n");
  return 0;
}

unsigned int updateState1(float deltaTime){
  printf("State 1 update %f\n", deltaTime);
  return 0;
}

unsigned int freeState1(){
  printf("State 1 free'd\n");
  return 0;
}


int main(int argc, char *argv[]){
  AsterOptions options = {.title = "Aster engine test hi mom", .width = 600, .height = 400};
  
  AsterEngine engine;
  ae_init(&engine, &options);

  State state1;
  state1.init = initState1;
  state1.update = updateState1;
  state1.free = freeState1;

  sm_push(&engine.stateManager, &state1);

  SDL_Event e;
  while(!engine.quit){
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT) engine.quit = 1;
    }

    sm_update(&engine.stateManager, 10.0f);
  }

  ae_free(&engine);

  return 0;
}
