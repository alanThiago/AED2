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

void Destuir(No* d){
    if(d == NULL) return;
    Destuir(d->esq);
    Destuir(d->dir);
    free(d);
}

void Infixo(No* d){
    if(d == NULL) return;
    Infixo(d->esq);
    printf("%d ", d->chave);
    Infixo(d->dir);
}

void Prefixo(No* d){
    if(d == NULL) return;
    printf("%d ", d->chave);
    Prefixo(d->esq);
    Prefixo(d->dir);
}

void Posfixo(No* d){
    if(d == NULL) return;
    Posfixo(d->esq);
    Posfixo(d->dir);
    printf("%d ", d->chave);
}

void Imprimir(No* d){
    printf("Pre.: "); Prefixo(d);
    printf("\nIn..: "); Infixo(d);
    printf("\nPost: "); Posfixo(d);
    printf("\n");
}

int main(){
    No *arvore;
    int C, N, i, j;
    unsigned chave;

    scanf("%d", &C);
    j = 0;
    while(C--){
        scanf("%d", &N);
        Inicializar(&arvore);
        for(i = 0; i < N; i++){
            scanf("%u", &chave);
            Inserir(&arvore, chave);
        }
        printf("Case %d:\n", ++j); Imprimir(arvore); printf("\n");
        Destuir(arvore); Inicializar(&arvore);
    }

    return 0;
}