#include "vdinamico.h"

typedef struct{
    int tam;
    int ocupacao;
    void* *vetor;
} DadosVD;

VDinamico* criarVD(){
    VDinamico *vd = malloc(sizeof(VDinamico));

    DadosVD *d = malloc(sizeof(DadosVD));

    vd->dados = d;
    d->tam = 1;
    d->ocupacao = 0;
    d->vetor = malloc(sizeof(DadosVD)*d->tam);

    return vd;
}

void inserir(VDinamico *vd, void* carga, int pos){
    DadosVD *d = vd->dados;

    if(pos > d->tam){
        d->tam = pow(2, ceil(log2(pos)));
        d->vetor = realloc(d->vetor, sizeof(void*)*(d->tam));
    }

    d->vetor[pos-1] = carga;
    d->ocupacao++;
}

void* acessar(VDinamico *vd, int pos){
    DadosVD *d = vd->dados;
    void* carga = NULL;
    
    if(pos <= d->tam) carga = d->vetor[pos-1];
    else printf("Acesso fora do limite\n");

    return carga;
}

void* remover(VDinamico *vd, int pos){
    DadosVD *d = vd->dados;
    void* carga = NULL;

    if(pos <= d->tam){
        carga = d->vetor[pos-1];

        if(carga){
            d->vetor[pos-1] = NULL;
            d->ocupacao--;
        }
    }
    return carga;
}