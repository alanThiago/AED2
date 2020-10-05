#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Autor{
    struct Autor *prox;
    unsigned votos;
    char nome[31];
} Autor;

typedef struct{
    Autor *prim, *ult;
} Fila;

Fila* CriarFila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->prim = NULL;
    return f;
}

void Inserir(Fila *f, char *nome){
    Autor *aux = f->prim;
    while(aux){
        if(!strcmp(aux->nome, nome)){ aux->votos++; return; }
        aux = aux->prox;
    }

    aux = (Autor*) malloc(sizeof(Autor));
    strcpy(aux->nome, nome);
    aux->votos = 1;
    aux->prox = NULL;

    if(f->prim){
        f->ult->prox = aux;
        f->ult = aux;
        return;
    }

    f->prim = f->ult = aux;
}

void Imprimir(Fila *f){
    Autor *aux = f->prim;

    while(aux){
        printf("Autor: %s, Votos: %u\n", aux->nome, aux->votos);
        aux = aux->prox;
    }
}

int main(){
    Fila *autores = CriarFila();
    char nome[31];

    while(scanf("%s", nome) != EOF) Inserir(autores, nome);
    Imprimir(autores);

    return 0;
}