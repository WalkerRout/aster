#ifndef STATEMANAGER_H
#define STATEMANAGER_H

typedef struct {
  unsigned int (*init)();
  unsigned int (*free)();

  unsigned int (*update)(float);
  unsigned int (*draw)(float);
} State;

#define STATEMANAGER_STACK_MIN_CAP 3

typedef struct {
  State **stack;

  int capacity;
  int top;
} StateManager;

int sm_init(StateManager *sm);
int sm_free(StateManager *sm);
int sm_push(StateManager *sm, State *state);
int sm_pop(StateManager *sm);
State *sm_peekTop(StateManager *sm);
int sm_update(StateManager *sm, float deltaTime);
int sm_draw(StateManager *sm, float deltaTime);

#endif // STATEMANAGER_H