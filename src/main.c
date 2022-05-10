#include <stdio.h>
#include <stdlib.h>

#include "include/asterengine.h"

// Global Engine Singleton
static AsterEngine engine = {0};


unsigned int initState1(){
  printf("State 1 created\n");
  return 0;
}

unsigned int updateState1(float deltaTime){
  printf("State 1 update %f\n", deltaTime);
  return 0;
}

unsigned int drawState1(float deltaTime){
  SDL_SetRenderDrawColor(engine.graphics.renderer, 255, 0, 0, 255);
  for (int i = 0; i < engine.graphics.width; i++)
    SDL_RenderDrawPoint(engine.graphics.renderer, i, i);
  return 0;
}

unsigned int freeState1(){
  printf("State 1 free'd\n");
  return 0;
}



int main(int argc, char *argv[]){
  AsterOptions options = {0};
  options.title = "C engine test";
  options.width = 480;
  options.height = 272;
  
  ae_init(&engine, &options);

  State state1 = {0};
  state1.init = initState1;
  state1.update = updateState1;
  state1.draw = drawState1;
  state1.free = freeState1;

  sm_push(&engine.stateManager, &state1);

  unsigned long int currTime, prevTime = SDL_GetTicks();
  SDL_Event e;
  while(!engine.quit){

    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT) engine.quit = 1;
    }

    currTime = SDL_GetTicks();
    float dT = (currTime - prevTime) / 1000.0f; // milliseconds

    SDL_SetRenderDrawColor(engine.graphics.renderer, 255, 255, 255, 1);
    SDL_RenderClear(engine.graphics.renderer);
    // Start rendering here

    sm_update(&engine.stateManager, dT);
    sm_draw(&engine.stateManager, dT);
    
    // Finish rendering here
    prevTime = currTime;
    printf("Delta Time: %lf\n", dT);
    SDL_RenderPresent(engine.graphics.renderer);
    SDL_Delay(1); // 1 ms delay between frames
  }

  ae_free(&engine);

  return 0;
}
