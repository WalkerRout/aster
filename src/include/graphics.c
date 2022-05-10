
#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"

#define ASTER_GRAPHICS_DEFAULT_WIDTH 800
#define ASTER_GRAPHICS_DEFAULT_HEIGHT 600
#define ASTER_GRAPHICS_DEFAULT_TITLE "AsterEngine"


int g_init(Graphics *graphics){
  if(!graphics->title)          graphics->title  = ASTER_GRAPHICS_DEFAULT_TITLE;
  if(!graphics->width == 0)     graphics->width  = ASTER_GRAPHICS_DEFAULT_WIDTH;
  if(!graphics->height == 0)    graphics->height = ASTER_GRAPHICS_DEFAULT_HEIGHT;

  graphics->window = SDL_CreateWindow(graphics->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, graphics->width, graphics->height, SDL_WINDOW_SHOWN);
  
  if(graphics->window == NULL){
    SDL_Log("Unable to create window: %s", SDL_GetError());
    return 1;
  }

  graphics->renderer = SDL_CreateRenderer(graphics->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(graphics->renderer == NULL){
    SDL_Log("Unable to create renderer: %s", SDL_GetError());
    return 1;
  }

  return 0;
}



int g_free(Graphics *graphics){
  SDL_DestroyWindow(graphics->window);

  return 0;
}