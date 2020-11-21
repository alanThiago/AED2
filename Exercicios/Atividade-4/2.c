#include <stdio.h>
#include <stdlib.h>

typedef struct chave{
    struct chave *prox;
    struct chave* ant;
    int valor;
} chave;

typedef chave** lista;

lista criarLista(int m){
    int i;

    lista l = (lista) malloc(sizeof(chave*)*m);
    for(i = 0; i < m; i++)  l[i] = NULL;

    return l;
}

void inserir(lista l, int v, int i){
    chave *tmp = (chave*) malloc(sizeof(chave));
    tmp->valor = v;

    if(!l[i]){
        l[i] = tmp;
        tmp->prox = NULL;
        tmp->ant = NULL;
        return;
    }

    chave *aux = l[i];
    while(tmp->valor >= aux->valor && aux->prox) aux = aux->prox;

    if(tmp->valor < aux->valor){
        tmp->prox = aux;
        tmp->ant = aux->ant;
        aux->ant = tmp;
        if(l[i] == aux){
            l[i] = tmp;
            tmp->ant = NULL;
            return;
        }
        tmp->ant->prox = tmp;
    }
    else{
        tmp->ant = aux;
        tmp->prox = NULL;
        aux->prox = tmp;
    }
}

void BucketSort(int *v, int k, int m, int n){
    lista l = criarLista(m);
    chave *aux;
    int i, j;

    for(i = 0; i < k; i++){
        inserir(l, v[i], (v[i]*m)/(n+1));
    }

    for(i = 0; i < m; i++){
        printf("%d ", i);
        if(l[i] == NULL) printf("NULL");
        else{
            aux = l[i];
            while(aux){
                printf("%d ", aux->valor);
                aux = aux->prox;
            }
        }
        printf("\n");
    }
    for(i = 0, j = 0; i < m; i++){
        aux = l[i];
        while(aux){
            v[j] = aux->valor;
            aux = aux->prox;
            j++;
        }
    }
}

int main(){
    int m, k, n, i, *v;

    scanf("%d%d%d", &m, &k, &n);
    v = (int*) malloc(sizeof(int)*k);

    for(i = 0; i < k; i++){
        scanf("%d", &v[i]);
    }

    BucketSort(v, k, m, n);
    for(i = 0; i < k; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}