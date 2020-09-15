#include "fila-neutra.h"

typedef struct Celula{
    struct Celula *prox;    //Ponteiro para a proxima celula
    void *dado;
} Celula;

typedef struct{
    Celula *prim;           //Primeiro elemento da fila
    Celula *ult;            //Ultimo elemento da fila
    unsigned tamanho;       
} Fila;

void* CriarFilaNeutra(){
    FilaNeutra *fn = malloc(sizeof(FilaNeutra));
    Fila *f = malloc(sizeof(Fila));

    //Quando a fila esta vazia os ponteiros prim e ult armazenam NULL
    f->prim = NULL;    
    f->ult = NULL;
    f->tamanho = 0;
    fn->Dados = f;

    return fn;
}

void Enfileirar(FilaNeutra *fn, void* carga){
    Fila *f = fn->Dados;
    Celula *tmp = malloc(sizeof(Celula));
    
    tmp->dado = carga;
    tmp->prox = NULL;
    f->tamanho++;
    
    if(f->prim){
        f->ult->prox = tmp;
        f->ult = tmp;
        return;
    }
    f->prim = f->ult = tmp;
}

void* Desenfileirar(FilaNeutra *fn){
    Fila *f = fn->Dados;
    Celula *tmp = f->prim;
    void *dado = tmp->dado;

    f->tamanho--;
    f->prim = tmp->prox;
    if(!f->prim) f->ult = NULL;
    free(tmp);

    return dado;
}

void FNEsvaziar(FilaNeutra *fn){
    Fila *f = fn->Dados;
    Celula *ant = f->prim;
    Celula *atual;

    while(ant){
        atual = ant->prox;
        free(ant->dado);
        free(ant);
        ant = atual;
    }

    f->prim = f->ult = NULL;
    f->tamanho = 0;
}

char FNVazia(FilaNeutra *fn){
    Fila *f = fn->Dados;
    return !f->tamanho;
}

unsigned FNTamanho(FilaNeutra *fn){
    Fila *f = fn->Dados;
    return f->tamanho;
}