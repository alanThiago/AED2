#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *prox;
    int dado;
} Celula;

typedef struct Lista{
    Celula *prim;
    Celula *ult;
} Lista;

void Criar(Lista *l){
    l->prim = l->ult = NULL;
}

void Inserir(Lista *l, int d){
    Celula *aux = (Celula*) malloc(sizeof(Celula));
    aux->prox = NULL;
    aux->dado = d;
    if(l->prim){
        l->ult->prox = aux;
        l->ult = aux;
        return;
    }
    l->prim = l->ult = aux;
}

void Imprimir(Lista *l){
    Celula *aux = l->prim;
    while(aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

Celula* Ultimo(Celula *c, Celula *fim){
    if(c->prox != fim) return Ultimo(c->prox, fim);
    return c;
}

void Inverter(Lista *l, Celula *fim){
    if(l->prim != l->ult){
        Celula *prim = l->prim;
        Celula *prox = prim->prox;
        Celula *ult = Ultimo(prox, fim);
        prim->prox = ult->prox;
        ult->prox = prim;
        l->prim = prox;
        Inverter(l, prim);
    }
}

void InverterLista(Lista *l){
    Celula *fim = l->prim;
    Inverter(l, NULL);
    l->ult = fim;
}

int main(){
    Lista l;
    int d;

    Criar(&l);
    
    while(scanf("%d", &d) != EOF) Inserir(&l, d);
    InverterLista(&l);
    Imprimir(&l);

    return 0;
}