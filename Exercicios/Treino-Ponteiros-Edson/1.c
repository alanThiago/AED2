#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *prox;
    int dado;
} Celula;

typedef struct{
    Celula *prim;
    Celula *ult;
} Lista;

void CriarLista(Lista *l){
    l->prim = NULL;
    l->ult = NULL;
}

void Inserir(Lista *l, int d){
    Celula *tmp = (Celula *) malloc(sizeof(Celula));
    
    tmp->dado = d;
    tmp->prox = NULL;

    if(l->prim != NULL){
        l->ult->prox = tmp;
        l->ult = tmp;
        return;
    }
    l->prim = l->ult = tmp;
}

void Imprimir(Lista *l){
    Celula *tmp = l->prim;

    while(tmp){
        printf(" %d", tmp->dado);
        tmp = tmp->prox;
    }
    printf("\n");
}

void RemoverRepeticoes(Lista *l){
    Celula *tmp = l->prim;
    Celula *ant, *atual;

    while(tmp){
        ant = tmp;
        while(ant && ant->prox){
            atual = ant->prox;
            if(atual->dado == tmp->dado){
                ant->prox = atual->prox;
                free(atual);
            }
            else ant = ant->prox;
        }
        tmp = tmp->prox;
    }
}

char NaoEsta(Lista *l, int d){
    Celula *tmp = l->prim;

    while(tmp){
        if(tmp->dado == d) return 0;
        tmp = tmp->prox;
    }
    return 1;
}

void Uniao(Lista *l1, Lista *l2){
    Celula *tmp = l1->prim;

    while(tmp){
        printf(" %d", tmp->dado);
        tmp = tmp->prox;
    }

    tmp = l2->prim;
    while(tmp){
        if(NaoEsta(l1, tmp->dado)) printf(" %d", tmp->dado);
        tmp = tmp->prox;
    }
    printf("\n");
}

void Intersecao(Lista *l1, Lista *l2){
    Celula *tmp = l1->prim;

    while(tmp){
        if(!NaoEsta(l2, tmp->dado)) printf(" %d", tmp->dado);
        tmp = tmp->prox;
    }
    printf("\n");
}

int main(){
    Lista l1;
    Lista l2;
    int d;

    CriarLista(&l1);
    CriarLista(&l2);

    scanf("%d", &d);
    while(d){
        Inserir(&l1, d);
        scanf("%d", &d);
    }

    scanf("%d", &d);
    while(d){
        Inserir(&l2, d);
        scanf("%d", &d);
    }

    printf("Lista 1:"); Imprimir(&l1);
    printf("Lista 2:"); Imprimir(&l2);
    
    RemoverRepeticoes(&l1);
    RemoverRepeticoes(&l2);
    printf("Uniao:"); Uniao(&l1, &l2);
    printf("Intersecao:"); Intersecao(&l1, &l2);

    return 0;
}