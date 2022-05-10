OBJS = src/*.c src/include/*.c
OBJ = bin/aster
CFLAGS = -Wall -Wpedantic
LIBS = -lSDL2 -lSDL2main

all: build run

build:
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(OBJ)

run:
	@./$(OBJ)
