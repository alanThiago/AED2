#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No *esq, *dir;
    unsigned chave;
} No;

void Inicializar(No** d){
    *d = NULL;
}

void Inserir(No** d, unsigned chave){
    if(*d == NULL){
        *d = (No*) malloc(sizeof(No));
        (*d)->chave = chave;
        (*d)->dir = (*d)->esq = NULL;
        return;
    }
    if(chave < (*d)->chave){ Inserir(&(*d)->esq, chave); return; }
    if(chave > (*d)->chave){ Inserir(&(*d)->dir, chave); return; }
}

int max(int a, int b){
    if(a >= b) return a;
    return b;
}

int TreeHeight(No* d){
    if(d == NULL) return -1;
    return 1 + max(TreeHeight(d->esq), TreeHeight(d->dir));
}

char IsAVL(No* d){
    int esq, dir;
    char flag = 1;
    if(d){
        flag = IsAVL(d->esq);
        if(flag) flag = IsAVL(d->dir);
        if(flag){
            esq = TreeHeight(d->esq);
            dir = TreeHeight(d->dir);
            if(esq-dir < -1 || esq-dir > 1) return 0;
        }
    }
    return flag;
}

int main(){
    unsigned N, chave, i;
    No* arvore;

    Inicializar(&arvore);
    scanf("%u", &N);

    for(i = 0; i < N; i++){
        scanf("%u", &chave);
        Inserir(&arvore, chave);
    }

    printf("%s\n", IsAVL(arvore) ? "SIM" : "NAO");
    return 0;
}