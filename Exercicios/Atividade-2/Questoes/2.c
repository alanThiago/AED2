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

int Decrementar(Lista *l, int Q){
    Celula *aux = l->prim;
    
    if(aux){
        if(aux->dado > Q){
            aux->dado -= Q;

            if(aux->prox){
                Celula *ant = aux->prox;
                l->prim = ant;
                while(ant->prox) ant = ant->prox;
                ant->prox = aux;
                aux->prox = NULL;
            }

            return Q;
        }

        l->prim = aux->prox;
        int T = aux->dado;
        free(aux);
        
        if(l->prim) return Q;
        return T;
    }
    return 0;
}

int main(){
    Lista l;
    int tempo = 0;
    int Q;
    int dado;

    CriarLista(&l);

    scanf("%d", &Q);
    while(scanf("%d", &dado) != EOF) Inserir(&l, dado);

    while(dado = Decrementar(&l, Q)) tempo += dado;
    printf("%d\n", tempo);

    return 0;
}