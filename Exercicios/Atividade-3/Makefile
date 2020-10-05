QUESTOES = $(wildcard ./Questoes/*.c)
EXECUTAVEIS = $(subst .c,,$(subst Questoes/,,$(QUESTOES)))
CC = gcc
FLAGS = -c -Wall -lm

all: folders $(EXECUTAVEIS)

./Objetos/%.o: ./Questoes/%.c
	$(CC) $(FLAGS) $< -o $@

./%: ./Objetos/%.o
	$(CC) $< -o $@

folders:
	@ mkdir -p Objetos

clean:
	rm -rf Objetos/ $(EXECUTAVEIS)

.PHONY: all clean folders