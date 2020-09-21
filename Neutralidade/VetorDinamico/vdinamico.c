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

//static faz a função ficar restrita a esse arquivo e não gera comflitos com outras que não tem o msm nome
static void trocar(void** v, int i, int j){
    void* temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void ordenar(VDinamico *vd, ComparaVD comparar){
    DadosVD *v = vd->dados;
    int i, j, n;

    void *pivot;
    n = v->ocupacao;

    for(i = 1; i < n; i++){
        pivot = v->vetor[i];
        for(j = i-1; (j > -1) && comparar(pivot, v->vetor[j]); --j) trocar(v->vetor, j, j+1);
        v->vetor[j+1] = pivot;
    }
}