#include "pilha-neutra.h"

typedef struct Celula{
    struct Celula *prox;
    void* dado;
} Celula;

typedef struct{
    Celula *prim;
    unsigned tamanho;
} Pilha;

void* CriarPilhaNeutra(){
    PilhaNeutra *pn = malloc(sizeof(PilhaNeutra));
    Pilha *p = malloc(sizeof(Pilha));

    p->prim = NULL;
    p->tamanho = 0;
    pn->dados = p;

    return pn;
}

void Empilhar(PilhaNeutra *pn, void* carga){
    Pilha *p = pn->dados;
    Celula *aux = malloc(sizeof(Celula));

    aux->dado = carga;
    aux->prox = p->prim;
    p->prim = aux;
    p->tamanho++;
}

void* Desempilhar(PilhaNeutra *pn){
    Pilha *p = pn->dados;
    Celula *aux = p->prim;
    void *tmp = aux->dado;

    p->prim = aux->prox;
    free(aux);
    p->tamanho--;

    return tmp;
}

void PNEsvaziar(PilhaNeutra *pn){
    Pilha *p = pn->dados;
    Celula *ant = p->prim;
    Celula *atual;

    while(ant){
        atual = ant->prox;
        free(ant->dado);
        free(ant);
        ant = atual;
    }
    p->tamanho = 0;
    p->prim = NULL;
}

unsigned PNTamanho(PilhaNeutra *pn){
    Pilha *p = pn->dados;
    return p->tamanho;
}

char PNVazia(PilhaNeutra *pn){
    Pilha *p = pn->dados;
    return !p->tamanho;
}