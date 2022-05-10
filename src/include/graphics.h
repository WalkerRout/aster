#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

typedef struct {
  char *title;
  int width;
  int height;
  SDL_Window *window;
  SDL_Renderer *renderer;
} Graphics;

int g_init(Graphics *graphics);
int g_free(Graphics *graphics);

#endif // GRAPHICS_H