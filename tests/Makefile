CC = gcc
LD = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../include -O0 -g -pg
LDFLAGS = -lm -pg

# Par défaut, on compile tous les fichiers test (.c) qui se trouvent dans le dossier tests
SRC_FILES=$(wildcard *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)
TESTS=$(SRC_FILES:.c=-test)

INCLUDE_FILES_PROJET=$(wildcard ../include/*.h)
SRC_FILES_PROJET:=$(patsubst ../include/%.h,../src/%.c,$(INCLUDE_FILES_PROJET))
SRC_FILES_PROJET:=$(filter-out ../src/macros.c, $(SRC_FILES_PROJET)) # macros.c n'existe pas
OBJ_FILES_PROJET=$(patsubst ../src/%.c,../obj/%.o,$(SRC_FILES_PROJET))



all: $(TESTS)

# COMPILATION DU PROJET
../obj/%.o:
	make $(patsubst ../%,%,$(OBJ_FILES_PROJET)) -C ../

# EDITION DE LIENS
%-test: %.o $(OBJ_FILES_PROJET)
	$(CC) $< $(OBJ_FILES_PROJET) -o $@ $(LDFLAGS)

# COMPILATION DES TESTS
%.o: %.c $(SRC_FILES_PROJET) $(INCLUDE_FILES_PROJET)
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf *-test
	rm -rf *.ppm