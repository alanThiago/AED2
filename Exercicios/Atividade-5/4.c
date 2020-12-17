#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No *esq, *dir;
    int valor, h;
} No;

void Inicializar(No** d){
    *d = NULL;
}

int maior(int a, int b){
    if(a >= b) return a;
    return b;
}

int altura_no(No* no){
    if(no == NULL) return -1;
    return no->h;
}

int fatorBalancemanto(No *no){
    return labs(altura_no(no->esq) - altura_no(no->dir));
}

void Esquerda(No** d){
    No *raiz = *d;
    
    *d = raiz->dir;
    raiz->dir = raiz->dir->esq;
    (*d)->esq = raiz;
}

void RotacaoLL(No** raiz){
    No *no = *raiz;

    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;

    (*raiz)->h = maior(altura_no((*raiz)->esq), altura_no((*raiz)->dir)) + 1;
    no->h = maior(altura_no(no->esq), (*raiz)->h + 1);

    *raiz = no;
}

void RotacaoRR(No** raiz){
    No *no = *raiz;

    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;

    (*raiz)->h = maior(altura_no((*raiz)->esq), altura_no((*raiz)->dir)) + 1;
    no->h = maior(altura_no(no->dir), (*raiz)->h + 1);

    *raiz = no;
}

void RotacaoLR(No** raiz){
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL(No** raiz){
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

int Inserir(No** raiz, int valor){
    int res;
    if(*raiz == NULL){
        No* novo = (No*) malloc(sizeof(No));
        if(novo == NULL) return 0;
        novo->valor = valor;
        novo->h = 0;
        novo->esq = novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    No* atual = *raiz;
    if(valor < atual->valor){
        if((res=Inserir(&atual->esq, valor))==1){
            if(fatorBalancemanto(atual)>=2){
                if(valor < (*raiz)->esq->valor) RotacaoLL(raiz);
                else RotacaoLR(raiz);
            }
        }
    }
    else if(valor > atual->valor){
        if((res=Inserir(&atual->dir, valor))==1){
            if(fatorBalancemanto(atual) >= 2){
                if((*raiz)->dir->valor < valor) RotacaoRR(raiz);
                else RotacaoRL(raiz);
            }
        }
        else return 0;
    }
    atual->h = maior(altura_no(atual->esq), altura_no(atual->dir)) + 1;
    return res;
}

void Prefixo(No* d){
    if(d == NULL) return;
    printf("%d ", d->valor);
    Prefixo(d->esq);
    Prefixo(d->dir);
}

int main(){
    No *arvore;
    int n, valor;

    Inicializar(&arvore);
    scanf("%u", &n);
    while(n--){
        scanf("%u", &valor);
        Inserir(&arvore, valor);
    }
    Prefixo(arvore);
    printf("\n");
    return 0;
}