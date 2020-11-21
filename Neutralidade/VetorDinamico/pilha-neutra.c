#include "pilha-neutra.h"

typedef struct{
    void **dados;
    unsigned tam;
    unsigned ocupacao;
} VD;

void* CriarPilhaNeutra(){
    PilhaNeutra *pn = (PilhaNeutra*) malloc(sizeof(PilhaNeutra));
    VD *v = (VD*) malloc(sizeof(VD));

    v->dados = (void**) malloc(sizeof(void*));
    v->tam = 1;
    v->ocupacao = 0;

    pn->dados = v;
    return pn;
}

void Empilhar(PilhaNeutra *pn, void* carga){
    VD *v = pn->dados;

    if(v->ocupacao == v->tam){
        v->tam *= 2;
        v->dados = (void**) realloc(v->dados, sizeof(void*) * v->tam);
    }

    v->dados[v->ocupacao] = carga;
    v->ocupacao++;
}

void* Desempilhar(PilhaNeutra *pn){
    VD *v = pn->dados;

    if(v->tam){
       void *dado = v->dados[v->ocupacao-1]; 
       v->ocupacao--;
       return dado;
    }
    return NULL;
}

unsigned PNTamanho(PilhaNeutra *pn){
    VD *v = pn->dados;
    return v->ocupacao;
}

void PNEsvaziar(PilhaNeutra *pn){
    VD *v = pn->dados;

    for(unsigned i = 0; i < v->ocupacao; i++){
        free(v->dados[i]);
    }

    v->tam = 1;
    v->ocupacao = 0;
    v->dados = (void**) realloc(v->dados, sizeof(void*));
}

char PNVazia(PilhaNeutra *pn){
    VD *v = pn->dados;
    return v->ocupacao == 0;
}