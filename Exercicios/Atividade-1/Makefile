QUESTOES = $(wildcard ./Questoes/*.c)
OBJETOS = $(subst .c,.o,$(subst Questoes,Objetos,$(QUESTOES)))
EXECUTAVEIS = $(subst .c,,$(subst Questoes/,,$(QUESTOES)))
CC = gcc
FLAGS = -c -Wall -lm

all: folders $(OBJETOS) $(EXECUTAVEIS)

./Objetos/%.o: ./Questoes/%.c
	$(CC) $(FLAGS) $< -o $@

./%: ./Objetos/%.o
	$(CC) $< -o $@

folders:
	@ mkdir -p Objetos

clean:
	rm -rf Objetos/ $(EXECUTAVEIS)

.PHONY: all clean folders