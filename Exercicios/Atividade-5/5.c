#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0

typedef int bool;

typedef struct NO{
    struct NO *esq, *dir;
    int chave, h;
} NO, *PONT;

PONT criaNo(int ch){
    PONT no = (PONT) malloc(sizeof(NO));
    no->esq = no->dir = NULL;
    no->chave = ch;
    no->h = 0;
    return no;
}

PONT inicializa(){
    return NULL;
}

int max(int a, int b){
    if(a >= b) return a;
    return b;
}

int altura(PONT raiz){
    if(!raiz) return -1;
    return raiz->h;
}

PONT direita(PONT r){
    PONT aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;

    r->h = max(altura(r->esq), altura(r->dir)) + 1;
    aux->h = max(altura(aux->esq), r->h) + 1;
    return aux;
}

PONT esquerda(PONT r){
    PONT aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;

    r->h = max(altura(r->esq), altura(r->dir)) + 1;
    aux->h = max(altura(aux->dir), r->h) + 1;
    return aux;
}

PONT esquerdaDireita(PONT r){
    r->esq = esquerda(r->esq);
    return direita(r);
}

PONT direitaEsquerda(PONT r){
    r->dir = direita(r->dir);
    return esquerda(r);
}

PONT insere(PONT raiz, int ch){
    if(!raiz) return criaNo(ch);
    if(ch < raiz->chave){
        raiz->esq = insere(raiz->esq, ch);
        if((altura(raiz->esq) - altura(raiz->dir) == 2)){
            printf("%d\n", raiz->chave);
            if(ch < raiz->esq->chave) raiz = direita(raiz);
            else raiz = esquerdaDireita(raiz);
        }
    }
    else if(ch > raiz->chave){
        raiz->dir = insere(raiz->dir, ch);
        if((altura(raiz->dir) - altura(raiz->esq) == 2)){
            printf("%d\n", raiz->chave);
            if(ch > raiz->dir->chave) raiz = esquerda(raiz);
            else raiz = direitaEsquerda(raiz);
        }
    }
    raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;
    return raiz;
}

PONT sucessor(PONT dir){
    PONT esq = dir->esq;

    while(esq){
        dir = esq;
        esq = dir->esq;
    }
    return dir;
}

void remover(PONT *raiz, int valor){
    if(*raiz == NULL){
        printf("Valor não existe\n");
        return;
    }

    int res;
    if(valor < (*raiz)->chave){
        remover(&(*raiz)->esq, valor);
        if(altura((*raiz)->dir) - altura((*raiz)->esq) == 2){
            printf("%d\n", (*raiz)->chave);
            if(altura((*raiz)->dir->esq) <= altura((*raiz)->dir->dir))
                *raiz = esquerda(*raiz);
            else
                *raiz = direitaEsquerda(*raiz);
        }
    }
    else if(valor > (*raiz)->chave){
        remover(&(*raiz)->dir, valor);
        if(altura((*raiz)->esq) - altura((*raiz)->dir) == 2){
            printf("%d\n", (*raiz)->chave);
            if(altura((*raiz)->esq->dir) <= altura((*raiz)->esq->esq))
                *raiz = direita(*raiz);
            else
                *raiz = esquerdaDireita(*raiz);
        }
    }
    else{
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
            PONT aux = *raiz;
            if(aux->esq == NULL)
                *raiz = aux->dir;
            else
                *raiz = aux->esq;
            free(aux);
        }
        else{
            PONT aux = sucessor((*raiz)->dir);
            (*raiz)->chave = aux->chave;
            remover(&(*raiz)->dir, aux->chave);
            if(altura((*raiz)->esq) - altura((*raiz)->dir) == 2){
                printf("%d\n", (*raiz)->chave);
                if(altura((*raiz)->esq->dir) <= altura((*raiz)->esq->esq))
                    *raiz = direita(*raiz);
                else
                    *raiz = esquerdaDireita(*raiz);
            }
        }
    }
}

void Infixo(PONT d){
    if(d == NULL) return;
    Infixo(d->esq);
    printf("%d ", d->chave);
    Infixo(d->dir);
}

void Prefixo(PONT d){
    if(d == NULL) return;
    printf("%d ", d->chave);
    Prefixo(d->esq);
    Prefixo(d->dir);
}

void Posfixo(PONT d){
    if(d == NULL) return;
    Posfixo(d->esq);
    Posfixo(d->dir);
    printf("%d ", d->chave);
}

int main(){
    PONT raiz = inicializa();
    int n, x;
    char r[5];

    scanf("%d", &n);
    while(n--){
        scanf("%s%d", r, &x);
        if(r[0] == 'i') raiz = insere(raiz, x);
        else remover(&raiz, x);
    }
    

    Prefixo(raiz); printf("\n");
    Infixo(raiz); printf("\n");
    Posfixo(raiz); printf("\n");
}