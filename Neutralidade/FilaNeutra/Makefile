# Name of the project
PROJ_NAME=TesteFN

# .c files
C_SOURCE=$(wildcard ./modules/*.c)

# .h files
H_SOUCES=$(wildcard ./headers/*.h)

# .o files
O_SOURCES=./objects

# Object files
OBJ=$(subst .c,.o,$(subst modules,objects,$(C_SOURCE)))

# Compiler
CC=gcc

#Flags for compiler
CC_FLAGS=-c    \
         -W    \
         -Wall \
         -ansi \
         -pedantic \
         -std=c99

# Command used at clean target
RM = rm -rf

#
# Compilation and  linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ) $(O_SOURCES)/main.o
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

$(O_SOURCES)/%.o: ./modules/%.c ./headers/%.h
	@ echo 'Building targets using GCC compiler: $<'
	$(CC) -o $@ $< -I $(CC_FLAGS)
	@ echo ' '

$(O_SOURCES)/main.o: ./main.c $(H_SOUCES)
	@ echo 'Building targets using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME)
	@ rmdir objects

#Esse target é usado para não dar conflitos com outros arquivos que tenham o msm nome
.PHONY: all clean