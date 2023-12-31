#!/bin/bash

# obj
gcc -c src/main.c -o obj/main.o
gcc -c src/interface.c -o obj/interface.o
gcc -c src/event_handler.c -o obj/event_handler.o
gcc -c src/cube.c -o obj/cube.o
gcc -c src/projection_plane.c -o obj/projection_plane.o
gcc -c src/projector.c -o obj/projector.o
gcc -c src/world.c -o obj/world.o
gcc -c src/matrices.c -o obj/matrices.o
gcc -c src/player.c -o obj/player.o

# program
g++ obj/*.o -I/usr/include/SDL2/ -I. -Iinclude/ -lSDL2main -lSDL2 -g -o bin/game
