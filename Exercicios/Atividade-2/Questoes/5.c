#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char palavra[31];
    unsigned prioridade;
} Palavra;

typedef struct{
    Palavra *heap;
    unsigned ocupacao;
    unsigned tamanho;
} Heap;

char ehMaior(Palavra *a, Palavra *b){
    if(a->prioridade < b->prioridade) return 1;
    if(a->prioridade == b->prioridade && strcmp(a->palavra, b->palavra) > 0) return 1;
    return 0;
}

Heap* CriarHeap(){
    Heap *h = (Heap*) malloc(sizeof(Heap));

    h->ocupacao = 0;
    h->tamanho = 2;
    h->heap = (Palavra*) malloc(sizeof(Palavra)*2);
}

char NaoVazio(Heap *h){
    return h->ocupacao > 0;
}

void InserirNoHeap(Heap *h, Palavra *carga){
    if(h->ocupacao + 1 == h->tamanho){
        h->tamanho *= 2;
        h->heap = realloc(h->heap, sizeof(Palavra) * h->tamanho);
    }

    h->ocupacao++;
    h->heap[h->ocupacao] = *carga;
    unsigned j = h->ocupacao;
    unsigned i = j/2;
    Palavra tmp;

    while(i && ehMaior(&h->heap[i], &h->heap[j])){
        tmp = h->heap[i]; h->heap[i] = h->heap[j]; h->heap[j] = tmp;
        j = i; i = j/2;
    }
}

void RemoverMax(Heap *h){
    if(NaoVazio(h)){
        printf("%s\n", h->heap[1].palavra);

        h->heap[1] = h->heap[h->ocupacao];
        h->ocupacao--;

        unsigned i = 1;
        unsigned j = 2;
        Palavra p = h->heap[1];
        while(j <= h->ocupacao){
            if(j < h->ocupacao && ehMaior(&h->heap[j], &h->heap[j+1])) j++;

            if(ehMaior(&h->heap[j], &p)) break;

            h->heap[i] = h->heap[j];
            i = j; j = i*2;
        }
        h->heap[i] = p;
    }
}

int main(){
    Heap *h = CriarHeap();
    Palavra p;
    Palavra x;
    int comando;

    scanf("%d", &comando);
    while(comando){
        if(comando == 1){
            scanf("%u%s%*c", &p.prioridade, p.palavra);
            InserirNoHeap(h, &p);
        } else RemoverMax(h);
        scanf("%d", &comando);
    }

    return 0;
}