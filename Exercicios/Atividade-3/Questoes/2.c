#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned *v;
    unsigned ocupacao;
    unsigned tam;
} VD;

void imprimir(VD *vd){
    for(unsigned i = 0; i < vd->ocupacao; i++) printf("%u ", vd->v[i]);
    printf("\n");
}

VD* criarVD(){
    VD *vd = (VD*) malloc(sizeof(VD));

    vd->tam = 2;
    vd->ocupacao = 0;
    vd->v = (unsigned*) malloc(sizeof(unsigned)*2);

    return vd;
}

void inserir(VD *vd, unsigned carga, unsigned pos){
    if(pos+2 > vd->tam){
        vd->tam *= 2;
        vd->v = (unsigned*) realloc(vd->v, sizeof(unsigned)*(vd->tam + 1));
    }

    vd->v[pos] = carga;
    vd->ocupacao++;
}

void ShiftRight(VD *vd, unsigned pos){
    for(unsigned i = vd->ocupacao; i > pos; --i)
        vd->v[i] = vd->v[i-1];
}

void ShiftLeft(VD *vd, unsigned pos){
    for(unsigned i = pos; i < vd->ocupacao; i++)
        vd->v[i] = vd->v[i+1];
    vd->ocupacao--;
}

void InserirEArrastar(VD *vd, unsigned dado, unsigned pos){
    ShiftRight(vd, pos);
    inserir(vd, dado, pos);
}

int main(){
    unsigned n;
    unsigned i;
    unsigned dado;
    unsigned op, w;
    VD *vd = criarVD();

    scanf("%u", &n);
    for(i = 0; i < n; i++){
        scanf("%u", &dado);
        inserir(vd, dado, i);
    }

    scanf("%u", &n);
    for(i = 0; i < n; i++){
        scanf("%u%u", &op, &w);
        if(op){
            scanf("%u", &dado);
            InserirEArrastar(vd, dado, w-1);
        } else ShiftLeft(vd, w-1);
    }

    imprimir(vd);

    return 0;
}