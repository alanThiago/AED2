#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Autor{
    unsigned votos;
    char nome[31];
} Autor;

typedef struct{
    Autor *v;
    unsigned ocupacao;
    unsigned size;
} Fila;

Fila* CriarFila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->ocupacao = 0;
    f->size = 1;
    f->v = (Autor*) malloc(sizeof(Autor));
    return f;
}

void Inserir(Fila *f, char *nome){
    for(unsigned i = 0; i < f->ocupacao; i++){
        if(!strcmp(f->v[i].nome, nome)){
            f->v[i].votos++;
            return;
        }
    }

    if(f->ocupacao == f->size){
        f->size *= 2;
        f->v = (Autor*) realloc(f->v, f->size * sizeof(Autor));
    }

    strcpy(f->v[f->ocupacao].nome, nome);
    f->v[f->ocupacao].votos = 1;
    f->ocupacao++;
}

void Imprimir(Fila *f){
    for(unsigned i = 0; i < f->ocupacao; i++)
        printf("Autor: %s, Votos: %u\n", f->v[i].nome, f->v[i].votos);
}

int main(){
    Fila *autores = CriarFila();
    char nome[31];

    while(scanf("%s", nome) != EOF) Inserir(autores, nome);
    Imprimir(autores);

    return 0;
}