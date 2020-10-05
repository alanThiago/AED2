#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void *dado;
    char tipo;
} Dado;

typedef struct{
    int tam;
    int ocupacao;
    Dado *vetor;
} VD;

typedef struct{
    int ano;
    char marca[51];
    char placa[51];
} Passeio;

typedef struct{
    int eixos;
    int capacidade;
    int ano;
    char placa[51];
    char marca[51];
} Carga;

typedef struct{
    double aluguel;
    int ano;
    char placa[51];
    char marca[51];
    char tipo[51];
} Pesados;

VD* criarVD(){
    VD *vd = malloc(sizeof(VD));

    vd->tam = 1;
    vd->ocupacao = 0;
    vd->vetor = (Dado*) malloc(sizeof(Dado));

    return vd;
}

void Empilhar(VD *vd, void* carga, char tipo){
    if(vd->ocupacao == vd->tam){
        vd->tam *= 2;
        vd->vetor = (Dado*) realloc(vd->vetor, sizeof(Dado)*(vd->tam));
    }

    vd->vetor[vd->ocupacao].dado = carga;
    vd->vetor[vd->ocupacao].tipo = tipo;
    vd->ocupacao++;
}

void Desempilhar(VD *vd){
    if(vd->ocupacao){
        free(vd->vetor[--vd->ocupacao].dado);
    }
}

void* LerPasseio(Passeio *p){ scanf("%s%d%s", p->marca, &p->ano, p->placa); return p; }
void ImprimirPasseio(Passeio *p){printf("%s %d %s\n", p->marca, p->ano, p->placa);}

void* LerCarga(Carga *c){ scanf("%s%d%d%d%s", c->marca, &c->eixos, &c->capacidade, &c->ano, c->placa); return c; }
void ImprimirCarga(Carga *c){ printf("%s %d %d %d %s\n", c->marca, c->eixos, c->capacidade, c->ano, c->placa); }

void* LerPesados(Pesados *p){ scanf("%s%s%lf%d%s", p->marca, p->tipo, &p->aluguel, &p->ano, p->placa); return p; }
void ImprimirPesados(Pesados *p){ printf("%s %s %.2lf %d %s\n", p->marca, p->tipo, p->aluguel, p->ano, p->placa); }

void* CriarInstanciaPasseio(Passeio *p){
    Passeio *tmp = (Passeio*) malloc(sizeof(Passeio));
    *tmp = *p;
    return tmp;
}

void* CriarInstanciaCarga(Carga *c){
    Carga *tmp = (Carga*) malloc(sizeof(Carga));
    *tmp = *c;
    return tmp;
}

void* CriarInstanciaPesados(Pesados *p){
    Pesados *tmp = (Pesados*) malloc(sizeof(Pesados));
    *tmp = *p;
    return tmp;
}

void ImprimirPilha(VD *vd){
    char tipo;
    for(int i = vd->ocupacao-1; i > -1; i--){
        tipo = vd->vetor[i].tipo;
        if(tipo == 1) ImprimirPasseio(vd->vetor[i].dado);
        else if(tipo == 2) ImprimirCarga(vd->vetor[i].dado);
        else ImprimirPesados(vd->vetor[i].dado);
    }
}

int main(){
    int tipoInstancia;
    Passeio pas;
    Carga car;
    Pesados pes;
    VD *pilha = criarVD();

    scanf("%d", &tipoInstancia);
    while(tipoInstancia != -1){
        if(tipoInstancia == 100) Empilhar(pilha, CriarInstanciaPasseio(LerPasseio(&pas)), (char)(tipoInstancia/100));
        else if(tipoInstancia == 200) Empilhar(pilha, CriarInstanciaCarga(LerCarga(&car)), (char)(tipoInstancia/100));
        else if(tipoInstancia == 300) Empilhar(pilha, CriarInstanciaPesados(LerPesados(&pes)), (char)(tipoInstancia/100));
        else Desempilhar(pilha);
        scanf("%d", &tipoInstancia);
    }

    ImprimirPilha(pilha);
    return 0;
}