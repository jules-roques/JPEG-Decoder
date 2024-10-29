CC = gcc
LD = gcc

# -O0 désactive les optimisations à la compilation
# C'est utile pour débugger, par contre en "production"
# on active au moins les optimisations de niveau 2 (-O2).
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -O0 -g -pg 
LDFLAGS = -lm -pg

# Par défaut, on compile tous les fichiers source (.c) qui se trouvent dans le
# répertoire src/
SRC_FILES=$(wildcard src/*.c)

# Par défaut, la compilation de src/toto.c génère le fichier objet obj/toto.o
OBJ_FILES=$(patsubst src/%.c,obj/%.o,$(SRC_FILES))

# Fichiers .h
INCLUDE_FILES=$(wildcard include/*.h)


all: jpeg2ppm

jpeg2ppm: $(OBJ_FILES)
	$(LD) $(OBJ_FILES) $(LDFLAGS) -o $@

obj/%.o: src/%.c $(INCLUDE_FILES)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean tests

tests:
	make jpeg2ppm
	make -C tests/

clean:
	rm -rf jpeg2ppm obj/*.o 
	rm -rf *.out
	rm -rf *.ppm
	rm -rf *.pgm
	rm -rf images/*.ppm
	rm -rf images/*.pgm
	make -C tests/ clean
