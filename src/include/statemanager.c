
#include <stdio.h>
#include <stdlib.h>

#include "statemanager.h"


static int sm_scale(StateManager *sm){
  sm->capacity *= 2;
  sm->stack = realloc(sm->stack, sm->capacity * sizeof(State *));

  return sm->capacity;
}



int sm_init(StateManager *sm){
  sm->capacity = STATEMANAGER_STACK_MIN_CAP; // minimum capacity
  sm->stack = malloc(sm->capacity * sizeof(State *));

  if(sm->stack == NULL){
    printf("Failed to allocate memory for the state manager stack!\n");
    return 1;
  }

  sm->top = -1;

  return 0;
}



int sm_free(StateManager *sm){
  do {
    sm_pop(sm);
  } while (sm->top > -1);

  free(sm->stack);
  return 0;
}



int sm_push(StateManager *sm, State *state){
  if(sm->top + 1 == sm->capacity) sm_scale(sm);
  sm->top++;
  sm->stack[sm->top] = state;
  // initialize state when pushed onto the stack if it has not been initialized previously
  if(state->init != NULL) state->init();
  
  return sm->top;
}



int sm_pop(StateManager *sm){
  if(sm->top == -1) return 0;
  State *top = sm_peekTop(sm);
  // free the state pointer if it has a pointer to a function to free it
  if(top->free != NULL) top->free();
  sm->stack[sm->top] = NULL;
  sm->top--;

  return sm->top;
}



State *sm_peekTop(StateManager *sm){
    return sm->stack[sm->top];
}



int sm_update(StateManager *sm, float deltaTime){
  State *state = sm_peekTop(sm);
  if(state->update != NULL) return state->update(deltaTime);
  return 1;
}



int sm_draw(StateManager *sm, float deltaTime){
  State *state = sm_peekTop(sm);
  if(state->draw != NULL) return state->draw(deltaTime);

  return 1;
}