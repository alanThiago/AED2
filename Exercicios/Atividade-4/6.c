#include <stdio.h>
#include <stdlib.h>

typedef struct part{
    struct part *prox;
    int j, n;
} part;

typedef struct fila{
    part *prim, *ult;
} fila;

fila* criarLista(){
    fila *tmp = (fila*) malloc(sizeof(fila));
    tmp->prim = NULL;
    return tmp;
}

void inserir(fila *f, part *d){
    part *tmp = (part*) malloc(sizeof(part));
    
    *tmp = *d;
    tmp->prox = NULL;
    if(f->prim){
        f->ult->prox = tmp;
        f->ult = tmp;
        return;
    }
    f->prim = f->ult = tmp;
}

void particiona(int *v, int *vaux, int n, fila *f){
    int size = n;
    int i, j = 0;
    part dados;

    while(size){
        i = 0;
        while(i < n && v[i] == 0) i++;
        vaux[j] = v[i];
        v[i++] = 0;
        dados.j = j;
        --size;

        while(i < n){
            if(v[i] > vaux[j]){
                vaux[++j] = v[i];
                v[i] = 0;
                --size;
            }
            i++;
        }
        ++j;

        dados.n = j;
        inserir(f, &dados);
    }
}

void merge(int *v, int *vaux, int n, fila *f){
    part *prim = f->prim;
    part *kpart = prim->prox;
    int i, j, k;

    while(kpart){
        k = 0;
        i = 0;
        j = kpart->j;
        
        while(i < prim->n && j < kpart->n){
            if(v[i] < v[j])
                vaux[k++] = v[i++];
            else
                vaux[k++] = v[j++];
        }

        while(i < prim->n) vaux[k++] = v[i++];
        while(j < kpart->n) vaux[k++] = v[j++];
        for(i = 0; i < k; i++) v[i] = vaux[i];

        prim->n = kpart->n;
        kpart = kpart->prox;
    }

    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void mergeInvan(int *v, int n){
    int *vaux = malloc(sizeof(int)*n);
    fila *f = criarLista();
    
    particiona(v, vaux, n, f);
    part *tmp = f->prim;
    for(int i = 0; i < n; i++){
        if(i == tmp->n){
            printf("\n");
            tmp = tmp->prox;
        }   
        printf("%d ", vaux[i]);
    }
    printf("\n");

    merge(vaux, v, n, f);
    free(vaux);
}

int main(){
    int v[206];
    int n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);
    mergeInvan(v, n);

    return 0;
}