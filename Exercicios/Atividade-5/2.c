#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Pesquisar(No* d, unsigned chave){
    if(d == NULL){ printf("%d nao existe\n", chave); return; }
    if(chave < d->chave){ Pesquisar(d->esq, chave); return; }
    if(chave > d->chave){ Pesquisar(d->dir, chave); return; }
    printf("%d existe\n", chave);
}

void Antecessor(No* x, No** r){
    if((*r)->dir != NULL){
        Antecessor(x, &(*r)->dir);
        return;
    }

    x->chave = (*r)->chave;
    x = *r; *r = x->esq;
    free(x);
}

void Remover(No** d, unsigned chave){
    if(*d == NULL) return;
    if(chave < (*d)->chave){ Remover(&(*d)->esq, chave); return; }
    if(chave > (*d)->chave){ Remover(&(*d)->dir, chave); return; }

    if((*d)->dir == NULL){
        No* aux = *d; *d = (*d)->esq;
        free(aux);
        return;
    }
    if((*d)->esq != NULL){
        Antecessor(*d, &(*d)->esq);
        return;
    }
    No* aux = *d; *d = (*d)->dir;
    free(aux);
}

int main(){
    No* arvore;
    unsigned chave;
    char op[8];

    Inicializar(&arvore);
    while(scanf("%s", op) != EOF){
        if(!strcmp(op, "INFIXA")) {Infixo(arvore); printf("\n"); }
        else if(!strcmp(op, "PREFIXA")){ Prefixo(arvore); printf("\n"); }
        else if(!strcmp(op, "POSFIXA")){ Posfixo(arvore); printf("\n"); }
        else if(op[0] == 'I'){
            scanf("%d", &chave);
            Inserir(&arvore, chave);
        }
        else if(op[0] == 'R'){
            scanf("%d", &chave);
            Remover(&arvore, chave);
        }
        else {
            scanf("%d", &chave);
            Pesquisar(arvore, chave);
        }
    }

    return 0;
}